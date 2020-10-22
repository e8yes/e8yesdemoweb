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

#include <optional>
#include <unordered_map>

#include "demoweb_service/demoweb/common_entity/message_channel_entity.h"
#include "demoweb_service/demoweb/common_entity/user_entity.h"
#include "demoweb_service/demoweb/pbac/message_channel_attributes.h"
#include "demoweb_service/demoweb/pbac/message_channel_member_attributes.h"
#include "demoweb_service/demoweb/pbac/message_channel_pbac.h"
#include "postgres/query_runner/connection/connection_reservoir_interface.h"
#include "proto_cc/message_channel.pb.h"

namespace e8 {

MessageChannelPbacInterface::MessageChannelPbacInterface() {}

MessageChannelPbacInterface::~MessageChannelPbacInterface() {}

MessageChannelPbacImpl::MessageChannelPbacImpl(ConnectionReservoirInterface *conns)
    : conns_(conns) {}

MessageChannelPbacImpl::~MessageChannelPbacImpl() {}

bool MessageChannelPbacImpl::AllowUpdateChannelMetadata(UserId const operator_user_id,
                                                        MessageChannelId const target_channel_id) {
    std::optional<MessageChannelAttributes> channel_attrs =
        ExtractMessageChannelAttributes(target_channel_id, conns_);
    if (!channel_attrs.has_value()) {
        return false;
    }

    std::optional<MessageChannelMemberAttributes> operator_attrs =
        ExtractMessageChannelMemberAttributes(target_channel_id, operator_user_id, conns_);
    if (!operator_attrs.has_value()) {
        return false;
    }

    if (*channel_attrs->close_group_channel.Value()) {
        return true;
    }

    return operator_attrs->member_type == MCMT_ADMIN;
}

bool MessageChannelPbacImpl::AllowDeleteChannel(UserId const operator_user_id,
                                                MessageChannelId const target_channel_id) {
    return this->AllowUpdateChannelMetadata(operator_user_id, target_channel_id);
}

bool MessageChannelPbacImpl::AllowUpdateChannelMembership(UserId const operator_user_id,
                                                          MessageChannelId const target_channel_id,
                                                          UserId const /*user_to_be_updated*/,
                                                          MessageChannelMemberType member_type) {
    std::optional<MessageChannelAttributes> channel_attrs =
        ExtractMessageChannelAttributes(target_channel_id, conns_);
    if (!channel_attrs.has_value()) {
        return false;
    }

    std::optional<MessageChannelMemberAttributes> operator_attrs =
        ExtractMessageChannelMemberAttributes(target_channel_id, operator_user_id, conns_);
    if (!operator_attrs.has_value()) {
        return false;
    }

    switch (member_type) {
    case MCMT_ADMIN:
        return operator_attrs->member_type == MCMT_ADMIN;

    case MCMT_MEMBER:
        if (*channel_attrs->close_group_channel.Value()) {
            return true;
        }
        return operator_attrs->member_type == MCMT_ADMIN;

    case MCMT_INVALID:
    default:
        return false;
    }
}

bool MessageChannelPbacImpl::AllowDeleteMemberFromChannel(UserId const operator_user_id,
                                                          MessageChannelId const target_channel_id,
                                                          UserId const user_to_be_removed) {
    std::optional<MessageChannelAttributes> channel_attrs =
        ExtractMessageChannelAttributes(target_channel_id, conns_);
    if (!channel_attrs.has_value()) {
        return false;
    }

    std::unordered_map<UserId, MessageChannelMemberAttributes> member_attrs =
        ExtractMessageChannelMemberAttributes(target_channel_id, conns_);
    auto operator_attr_it = member_attrs.find(operator_user_id);
    if (operator_attr_it == member_attrs.end()) {
        return false;
    }

    auto to_be_removed_attr_it = member_attrs.find(user_to_be_removed);
    if (to_be_removed_attr_it == member_attrs.end()) {
        return false;
    }

    if (operator_attr_it->second.member_type != MCMT_ADMIN) {
        return false;
    }
    if (operator_user_id == user_to_be_removed && member_attrs.size() == 1) {
        return false;
    }

    return true;
}

} // namespace e8