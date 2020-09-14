/**
 * e8yes demo web.
 *
 * <p>Copyright (C) 2020 Chifeng Wen {daviesx66@gmail.com}
 *
 * <p>This program is free software: you can redistribute it and/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * <p>This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * <p>You should have received a copy of the GNU General Public License along with this program. If
 * not, see <http://www.gnu.org/licenses/>.
 */

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <ctime>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "demoweb_service/demoweb/common_entity/message_channel_entity.h"
#include "demoweb_service/demoweb/common_entity/message_channel_has_user_entity.h"
#include "demoweb_service/demoweb/common_entity/user_entity.h"
#include "demoweb_service/demoweb/constant/demoweb_database.h"
#include "demoweb_service/demoweb/environment/host_id.h"
#include "demoweb_service/demoweb/module/message_channel.h"
#include "demoweb_service/demoweb/module/user_profile.h"
#include "demoweb_service/demoweb/module/user_storage.h"
#include "postgres/query_runner/connection/connection_reservoir_interface.h"
#include "postgres/query_runner/sql_query_builder.h"
#include "postgres/query_runner/sql_runner.h"
#include "proto_cc/message_channel.pb.h"
#include "proto_cc/pagination.pb.h"
#include "proto_cc/user_profile.pb.h"

namespace e8 {
namespace {

bool CanAdd(UserId const &viewer_id, MessageChannelId channel_id,
            MessageChannelMemberType const requesting_member_type,
            ConnectionReservoirInterface *conns) {
    SqlQueryBuilder query;
    SqlQueryBuilder::Placeholder<SqlLong> channel_id_ph;
    SqlQueryBuilder::Placeholder<SqlLong> viewer_id_ph;
    query.QueryPiece(TableNames::MessageChannelHasUser())
        .QueryPiece(" viewer WHERE viewer.channel_id=")
        .Holder(&channel_id_ph)
        .QueryPiece(" AND viewer.user_id=")
        .Holder(&viewer_id_ph);

    if (requesting_member_type == MCMT_ADMIN) {
        // Only admin can add another person as admin.
        SqlQueryBuilder::Placeholder<SqlInt> admin_member_type_ph;
        query.QueryPiece(" AND viewer.ownership=").Holder(&admin_member_type_ph);
        query.SetValueToPlaceholder(admin_member_type_ph,
                                    std::make_shared<SqlInt>(MessageChannelMemberType::MCMT_ADMIN));
    }

    query.SetValueToPlaceholder(channel_id_ph, std::make_shared<SqlLong>(channel_id));
    query.SetValueToPlaceholder(viewer_id_ph, std::make_shared<SqlLong>(viewer_id));

    return Exists(query, conns);
}

std::vector<std::vector<MessageChannelHasUserEntity>>
FetchMostActiveMembers(std::vector<MessageChannelId> const &message_channel_ids,
                       unsigned active_member_fetch_limit, ConnectionReservoirInterface *conns) {
    if (active_member_fetch_limit == 0) {
        return std::vector<std::vector<MessageChannelHasUserEntity>>(message_channel_ids.size());
    }

    SqlQueryBuilder member_query;
    SqlQueryBuilder::Placeholder<SqlLongArr> channel_ids_ph;
    member_query.QueryPiece(TableNames::MessageChannelHasUser())
        .QueryPiece(" mchu WHERE mchu.channel_id=ANY(")
        .Holder(&channel_ids_ph)
        .QueryPiece(")");

    member_query.SetValueToPlaceholder(channel_ids_ph,
                                       std::make_shared<SqlLongArr>(message_channel_ids));

    std::vector<std::tuple<MessageChannelHasUserEntity>> members =
        Query<MessageChannelHasUserEntity>(member_query, {"mchu"}, conns);

    // Group by channel ID.
    std::unordered_map<MessageChannelId, std::vector<MessageChannelHasUserEntity>> group_by_channel;
    for (auto const &entry : members) {
        MessageChannelHasUserEntity const &member = std::get<0>(entry);
        group_by_channel[*member.channel_id.Value()].push_back(member);
    }

    std::vector<std::vector<MessageChannelHasUserEntity>> result(message_channel_ids.size());
    for (unsigned i = 0; i < message_channel_ids.size(); ++i) {
        MessageChannelId channel_id = message_channel_ids[i];

        // Use last interaction timestamp as a criteria for activeness.
        std::vector<MessageChannelHasUserEntity> *members = &group_by_channel[channel_id];
        std::sort(members->begin(), members->end(),
                  [](MessageChannelHasUserEntity const &a, MessageChannelHasUserEntity const &b) {
                      return *a.last_interaction_at.Value() > *b.last_interaction_at.Value();
                  });

        // Trim to the limit and write out the IDs.
        std::vector<MessageChannelHasUserEntity>::iterator end_it;
        if (active_member_fetch_limit < members->size()) {
            end_it = members->begin() + active_member_fetch_limit;
            result[i].resize(active_member_fetch_limit);
        } else {
            end_it = members->end();
            result[i].resize(members->size());
        }

        std::copy(members->begin(), end_it, result[i].begin());
    }

    return result;
}

MessageChannel GetMessageChannel(SearchedMessageChannel const &searched_message_channel) {
    MessageChannel proto_message;
    proto_message.set_channel_id(*searched_message_channel.message_channel.id.Value());
    proto_message.set_title(*searched_message_channel.message_channel.channel_name.Value());
    proto_message.set_description(*searched_message_channel.message_channel.description.Value());
    proto_message.set_created_at(*searched_message_channel.message_channel.created_at.Value());
    return proto_message;
}

MessageChannelRelation
GetMessageChannelRelation(SearchedMessageChannel const &searched_message_channel) {
    MessageChannelRelation relation;
    relation.set_join_at(searched_message_channel.join_at);
    relation.set_member_type(searched_message_channel.member_type);
    return relation;
}

} // namespace

std::optional<MessageChannelEntity> CreateMessageChannel(
    UserId creator_id, std::optional<std::string> const &channel_name,
    std::optional<std::string> const &description, std::vector<UserId> const &to_be_member_ids,
    bool encrypted, bool close_group_channel, HostId host_id, ConnectionReservoirInterface *conns) {
    std::time_t current_timestamp;
    std::time(&current_timestamp);

    MessageChannelEntity message_channel;
    *message_channel.id.ValuePtr() = TimeId(host_id);
    *message_channel.channel_name.ValuePtr() = channel_name;
    *message_channel.description.ValuePtr() = description;
    *message_channel.encryption_enabled.ValuePtr() = encrypted;
    *message_channel.close_group_channel.ValuePtr() = close_group_channel;
    *message_channel.created_at.ValuePtr() = current_timestamp;

    int64_t num_rows =
        Update(message_channel, TableNames::MessageChannel(), /*replace=*/false, conns);
    assert(num_rows == 1);

    bool rc = AddUserToMessageChannel(/*viewer_id=*/std::nullopt, *message_channel.id.Value(),
                                      creator_id, MCMT_ADMIN, conns);
    if (rc == false) {
        return std::nullopt;
    }

    for (UserId const user_id : to_be_member_ids) {
        AddUserToMessageChannel(/*viewer_id=*/std::nullopt, *message_channel.id.Value(), user_id,
                                MCMT_MEMBER, conns);
    }

    return message_channel;
}

std::vector<SearchedMessageChannel> SearchMessageChannels(
    UserId const viewer_id, std::unordered_set<UserId> const &contains_member_ids,
    std::unordered_set<MessageChannelId> const &any_channel_ids,
    std::optional<std::string> const &query_text, unsigned active_member_fetch_limit,
    std::optional<Pagination> const &pagination, ConnectionReservoirInterface *conns) {
    // Build a list of required members each searched channel must contain.
    std::vector<UserId> must_have_user_ids{contains_member_ids.begin(), contains_member_ids.end()};
    if (contains_member_ids.find(viewer_id) == contains_member_ids.end()) {
        must_have_user_ids.push_back(viewer_id);
    }

    // Search message channels.
    SqlQueryBuilder message_channel_query;
    SqlQueryBuilder::Placeholder<SqlLongArr> contains_member_ids_ph;
    SqlQueryBuilder::Placeholder<SqlInt> must_have_user_count_ph;
    SqlQueryBuilder::Placeholder<SqlLong> viewer_id_ph;
    message_channel_query.QueryPiece("(SELECT mc.* FROM ")
        .QueryPiece(TableNames::MessageChannel())
        .QueryPiece(" mc")
        .QueryPiece(" JOIN ")
        .QueryPiece(TableNames::MessageChannelHasUser())
        .QueryPiece(" required_member ON required_member.channel_id=mc.id")
        .QueryPiece(" WHERE")
        .QueryPiece(" required_member.user_id=ANY(")
        .Holder(&contains_member_ids_ph)
        .QueryPiece(")");

    if (!any_channel_ids.empty()) {
        SqlQueryBuilder::Placeholder<SqlLongArr> any_channel_ids_ph;
        message_channel_query.QueryPiece(" AND mc.id=ANY(")
            .Holder(&any_channel_ids_ph)
            .QueryPiece(")");
        message_channel_query.SetValueToPlaceholder(
            any_channel_ids_ph, std::make_shared<SqlLongArr>(std::vector<MessageChannelId>{
                                    any_channel_ids.begin(), any_channel_ids.end()}));
    }

    message_channel_query.QueryPiece(" GROUP BY mc.id HAVING COUNT(required_member.user_id)=")
        .Holder(&must_have_user_count_ph)
        .QueryPiece(") AS qualified_channel")
        .QueryPiece(" JOIN ")
        .QueryPiece(TableNames::MessageChannelHasUser())
        .QueryPiece(" viewer ON viewer.channel_id=qualified_channel.id")
        .QueryPiece(" WHERE viewer.user_id=")
        .Holder(&viewer_id_ph)
        .QueryPiece(" ORDER BY viewer.last_interaction_at DESC");

    message_channel_query.SetValueToPlaceholder(contains_member_ids_ph,
                                                std::make_shared<SqlLongArr>(must_have_user_ids));
    message_channel_query.SetValueToPlaceholder(
        must_have_user_count_ph, std::make_shared<SqlInt>(must_have_user_ids.size()));
    message_channel_query.SetValueToPlaceholder(viewer_id_ph, std::make_shared<SqlLong>(viewer_id));

    std::vector<std::tuple<MessageChannelEntity, MessageChannelHasUserEntity>> channel_and_viewer;

    if (query_text.has_value()) {
        channel_and_viewer = Search<MessageChannelEntity, MessageChannelHasUserEntity>(
            message_channel_query, /*entity_aliases=*/{"qualified_channel", "viewer"},
            /*search_target_entity=*/{"qualified_channel"}, *query_text, /*prefix_search=*/true,
            /*rank_result=*/false, pagination->result_per_page(),
            pagination->result_per_page() * pagination->page_number(), conns);
    } else {
        if (pagination.has_value()) {
            SqlQueryBuilder::Placeholder<SqlInt> limit_ph;
            SqlQueryBuilder::Placeholder<SqlInt> offset_ph;
            message_channel_query.QueryPiece(" LIMIT ")
                .Holder(&limit_ph)
                .QueryPiece(" OFFSET ")
                .Holder(&offset_ph);
            message_channel_query.SetValueToPlaceholder(
                limit_ph, std::make_shared<SqlInt>(pagination->result_per_page()));
            message_channel_query.SetValueToPlaceholder(
                offset_ph, std::make_shared<SqlInt>(pagination->page_number() *
                                                    pagination->result_per_page()));
        }
        channel_and_viewer = Query<MessageChannelEntity, MessageChannelHasUserEntity>(
            message_channel_query, {"qualified_channel", "viewer"}, conns);
    }

    // Fetch the most active members for each message channel.
    std::vector<MessageChannelId> message_channel_ids(channel_and_viewer.size());
    for (unsigned i = 0; i < channel_and_viewer.size(); i++) {
        message_channel_ids[i] = *std::get<0>(channel_and_viewer[i]).id.Value();
    }
    std::vector<std::vector<MessageChannelHasUserEntity>> most_active_members =
        FetchMostActiveMembers(message_channel_ids, active_member_fetch_limit, conns);

    // Combine results.
    std::vector<SearchedMessageChannel> results(channel_and_viewer.size());
    for (unsigned i = 0; i < channel_and_viewer.size(); ++i) {
        auto const &entry = channel_and_viewer[i];

        SearchedMessageChannel result;
        result.message_channel = std::get<0>(entry);
        result.member_type =
            static_cast<MessageChannelMemberType>(*std::get<1>(entry).ownership.Value());
        result.join_at = *std::get<1>(entry).created_at.Value();
        result.most_active_members = most_active_members[i];

        results[i] = result;
    }

    return results;
}

std::vector<MessageChannelOverview>
ToMessageChannelOverviews(UserId const viewer_id,
                          std::vector<SearchedMessageChannel> const &searched_message_channels,
                          KeyGeneratorInterface *key_gen, ConnectionReservoirInterface *conns) {
    // Construct member profiles.
    std::unordered_map<UserId, UserPublicProfile> active_member_profiles;
    std::vector<UserId> unique_active_member_ids;
    for (auto const &searched_channel : searched_message_channels) {
        for (MessageChannelHasUserEntity const member : searched_channel.most_active_members) {
            UserId const member_id = *member.user_id.Value();
            auto it = active_member_profiles.find(member_id);
            if (it == active_member_profiles.end()) {
                active_member_profiles[member_id] = UserPublicProfile();
                unique_active_member_ids.push_back(member_id);
            }
        }
    }

    std::vector<UserEntity> members = FetchUsers(unique_active_member_ids, conns);
    std::vector<UserPublicProfile> member_profiles =
        BuildPublicProfiles(viewer_id, members, key_gen, conns);
    for (auto const &profile : member_profiles) {
        active_member_profiles[profile.user_id()] = profile;
    }

    // Compose the overiew.
    std::vector<MessageChannelOverview> result(searched_message_channels.size());
    for (unsigned i = 0; i < searched_message_channels.size(); ++i) {
        MessageChannelOverview overview;
        *overview.mutable_channel() = GetMessageChannel(searched_message_channels[i]);
        *overview.mutable_channel_relation() =
            GetMessageChannelRelation(searched_message_channels[i]);
        overview.set_channel_last_interacted_at(searched_message_channels[i].join_at);
        for (auto const &member : searched_message_channels[i].most_active_members) {
            *overview.mutable_most_active_users()->Add() =
                active_member_profiles[*member.user_id.Value()];
        }

        result[i] = overview;
    }

    return result;
}

std::vector<MessageChannelMember>
GetMessageChannelMembers(MessageChannelId channel_id, std::optional<Pagination> const &pagination,
                         ConnectionReservoirInterface *conns) {
    SqlQueryBuilder message_channel_member_query;
    SqlQueryBuilder::Placeholder<SqlLong> channel_id_ph;
    message_channel_member_query.QueryPiece(TableNames::AUser())
        .QueryPiece(" u")
        .QueryPiece(" JOIN ")
        .QueryPiece(TableNames::MessageChannelHasUser())
        .QueryPiece(" mchu ON mchu.user_id=u.id")
        .QueryPiece(" WHERE mchu.channel_id=")
        .Holder(&channel_id_ph)
        .QueryPiece(" ORDER BY mchu.last_interaction_at DESC");

    message_channel_member_query.SetValueToPlaceholder(channel_id_ph,
                                                       std::make_shared<SqlLong>(channel_id));

    if (pagination.has_value()) {
        SqlQueryBuilder::Placeholder<SqlInt> limit_ph;
        SqlQueryBuilder::Placeholder<SqlInt> offset_ph;
        message_channel_member_query.QueryPiece(" LIMIT ")
            .Holder(&limit_ph)
            .QueryPiece(" OFFSET ")
            .Holder(&offset_ph);
        message_channel_member_query.SetValueToPlaceholder(
            limit_ph, std::make_shared<SqlInt>(pagination->result_per_page()));
        message_channel_member_query.SetValueToPlaceholder(
            offset_ph,
            std::make_shared<SqlInt>(pagination->page_number() * pagination->result_per_page()));
    }

    std::vector<std::tuple<UserEntity, MessageChannelHasUserEntity>> query_result =
        Query<UserEntity, MessageChannelHasUserEntity>(message_channel_member_query, {"u", "mchu"},
                                                       conns);

    std::vector<MessageChannelMember> results(query_result.size());
    for (unsigned i = 0; i < query_result.size(); i++) {
        std::tuple<UserEntity, MessageChannelHasUserEntity> const &entry = query_result[i];

        MessageChannelMember result;
        result.member = std::get<0>(entry);
        result.member_type =
            static_cast<MessageChannelMemberType>(*std::get<1>(entry).ownership.Value());
        result.join_at = *std::get<1>(entry).created_at.Value();

        results[i] = result;
    }

    return results;
}

bool AddUserToMessageChannel(std::optional<UserId> const &viewer_id, MessageChannelId channel_id,
                             UserId const user_id, MessageChannelMemberType const member_type,
                             ConnectionReservoirInterface *conns) {
    if (viewer_id.has_value() && !CanAdd(*viewer_id, channel_id, member_type, conns)) {
        return false;
    }

    MessageChannelHasUserEntity channel_member;
    *channel_member.channel_id.ValuePtr() = channel_id;
    *channel_member.user_id.ValuePtr() = user_id;
    *channel_member.ownership.ValuePtr() = member_type;

    std::time_t timestamp;
    std::time(&timestamp);
    *channel_member.created_at.ValuePtr() = timestamp;
    *channel_member.last_interaction_at.ValuePtr() = timestamp;

    int64_t num_rows =
        Update(channel_member, TableNames::MessageChannelHasUser(), /*replace=*/false, conns);
    if (num_rows != 1) {
        return false;
    }

    return true;
}

} // namespace e8
