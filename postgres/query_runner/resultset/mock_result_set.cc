#include <cassert>
#include <memory>

#include "postgres/query_runner/reflection/sql_primitive_interface.h"
#include "postgres/query_runner/resultset/mock_result_set.h"

namespace e8 {

MockResultSet::MockResultSet(unsigned num_cells) : num_cells_(num_cells) {}

void MockResultSet::AddRecord(Record const &record) { records_.push_back(record); }

void MockResultSet::Next() {
    assert(cur_record_ < records_.size());
    ++cur_record_;
}

bool MockResultSet::HasNext() const { return cur_record_ < records_.size(); }

void MockResultSet::SetField(unsigned i, SqlPrimitiveInterface *field) {
    assert(i < num_cells_);
    Record const &record = records_[cur_record_];

    std::shared_ptr<SqlPrimitiveInterface> cell = record[i];
    if (cell == nullptr) {
        return;
    }

    *field = *cell;
}

} // namespace e8
