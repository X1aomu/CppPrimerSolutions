#include "common/text_query.h"

#include <sstream>

namespace cpp_primer {

using std::istringstream;
using std::set;
using std::shared_ptr;
using std::string;

TextQuery::TextQuery(std::ifstream &in) : file_input_(new InputType) {
  std::string line;
  while (std::getline(in, line)) {
    file_input_->push_back(line);
  }
  GenerateResult();
}

QueryResult TextQuery::Query(const std::string &word) const {
  static shared_ptr<set<LineNo>> nodata(new set<LineNo>);

  auto lines_ptr_itr = word_map_.find(word);
  if (lines_ptr_itr != word_map_.end()) {
    return QueryResult(word, lines_ptr_itr->second, file_input_);
  } else {
    return QueryResult(word, nodata, file_input_);
  }
}

void TextQuery::GenerateResult() {
  LineNo n = 0;
  for (auto line : *file_input_) {
    istringstream iss(line);
    string word;
    while (iss >> word) {
      auto &lines_ptr = word_map_[word];
      if (!lines_ptr) {
        lines_ptr.reset(new set<LineNo>);
      }
      lines_ptr->insert(n);
    }
    ++n;
  }
}

QueryResult::QueryResult(const std::string &word,
                         std::shared_ptr<std::set<TextQuery::LineNo>> lines_ptr,
                         std::shared_ptr<TextQuery::InputType> file_ptr)
    : word_(word), line_nos_ptr_(lines_ptr), file_ptr_(file_ptr) {}

std::ostream &QueryResult::Print(std::ostream &os) {
  os << "'" << word_ << "'"
     << " occurs " << line_nos_ptr_->size() << " time(s)" << std::endl;
  for (auto line_no : *line_nos_ptr_) {
    os << "\t"
       << "(line " << line_no + 1 << ") " << (*file_ptr_)[line_no] << std::endl;
  }
  return os;
}

std::set<TextQuery::LineNo>::iterator QueryResult::begin() const {
  return (*line_nos_ptr_).begin();
}

std::set<TextQuery::LineNo>::iterator QueryResult::end() const {
  return (*line_nos_ptr_).end();
}

std::shared_ptr<TextQuery::InputType> QueryResult::get_file() const {
  return file_ptr_;
}

} // namespace cpp_primer
