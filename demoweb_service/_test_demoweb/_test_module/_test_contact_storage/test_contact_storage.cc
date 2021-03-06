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
#include <vector>

#include "common/unit_test_util/unit_test_util.h"
#include "demoweb_service/demoweb/common_entity/user_entity.h"
#include "demoweb_service/demoweb/constant/demoweb_database.h"
#include "demoweb_service/demoweb/environment/test_environment_context.h"
#include "demoweb_service/demoweb/module/contact_storage.h"
#include "demoweb_service/demoweb/module/user_storage.h"
#include "message_queue/publisher/publisher.h"
#include "postgres/query_runner/sql_query_builder.h"
#include "postgres/query_runner/sql_runner.h"
#include "proto_cc/pagination.pb.h"
#include "proto_cc/user_relation.pb.h"

bool DeleteContactTest() {
    e8::DemoWebTestEnvironmentContext env;

    std::optional<e8::UserEntity> user1 =
        e8::CreateUser(/*security_key=*/"key", std::vector<std::string>(), /*user_id=*/1,
                       env.CurrentHostId(), env.DemowebDatabase());
    std::optional<e8::UserEntity> user2 =
        e8::CreateUser(/*security_key=*/"key", std::vector<std::string>(), /*user_id=*/2,
                       env.CurrentHostId(), env.DemowebDatabase());

    bool rc = e8::CreateContact(*user1->id.Value(), *user2->id.Value(), env.DemowebDatabase());
    TEST_CONDITION(rc == true);

    rc = e8::DeleteContact(*user1->id.Value(), *user2->id.Value(), env.DemowebDatabase());
    TEST_CONDITION(rc == true);

    e8::SqlQueryBuilder forward_query;
    forward_query.QueryPiece(e8::TableNames::ContactRelation())
        .QueryPiece(" cr ")
        .QueryPiece("WHERE cr.src_user_id=1 AND cr.dst_user_id=2 AND cr.relation=" +
                    std::to_string(e8::UserRelation::URL_CONTACT));
    bool exists_contact = e8::Exists(forward_query, env.DemowebDatabase());
    TEST_CONDITION(exists_contact == false);

    return true;
}

int main() {
    e8::BeginTestSuite("contact_storage");
    e8::RunTest("DeleteContactTest", DeleteContactTest);
    e8::EndTestSuite();
    return 0;
}
