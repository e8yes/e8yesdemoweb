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

#ifndef MESSAGE_GROUP_ENTITY_H
#define MESSAGE_GROUP_ENTITY_H

#include <cstdint>

#include "postgres/query_runner/reflection/sql_entity_interface.h"
#include "postgres/query_runner/reflection/sql_primitives.h"

namespace e8 {

using ChatMessageGroupId = int64_t;

/**
 * @brief The MessageGroupEntity class C++ class representation of the database table
 * "message_group".
 */
class ChatMessageGroupEntity : public SqlEntityInterface {
  public:
    ChatMessageGroupEntity();
    ChatMessageGroupEntity(ChatMessageGroupEntity const &other);
    ~ChatMessageGroupEntity() = default;

    ChatMessageGroupEntity &operator=(ChatMessageGroupEntity const &other);

    SqlLong id = SqlLong("id");
    SqlInt group_type = SqlInt("group_type");
    SqlLong channel_id = SqlLong("channel_id");
    SqlLong creator_id = SqlLong("creator_id");
    SqlStr description = SqlStr("description");
    SqlTimestamp created_at = SqlTimestamp("created_at");
    SqlTimestamp last_interaction_at = SqlTimestamp("last_interaction_at");
};

} // namespace e8

#endif // MESSAGE_GROUP_ENTITY_H
