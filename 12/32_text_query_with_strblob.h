#ifndef CPS_TEXT_QUERY_WITH_STRBLOB_H_
#define CPS_TEXT_QUERY_WITH_STRBLOB_H_

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

#include "common/str_blob.h"

namespace cps {

class QueryResult;

class TextQuery {
public:
  using InputType = StrBlob;
  using LineNo = InputType::size_type;

  TextQuery(std::ifstream &in);

  QueryResult Query(const std::string &word) const;

private:
  std::shared_ptr<InputType> file_input_;
  std::map<std::string, std::shared_ptr<std::set<LineNo>>> word_map_;

  void GenerateResult();
};

class QueryResult {
public:
  QueryResult(const std::string &word,
              std::shared_ptr<std::set<TextQuery::LineNo>> lines_ptr,
              std::shared_ptr<TextQuery::InputType> file_ptr);

  std::ostream &Print(std::ostream &os);

private:
  const std::string word_;
  const std::shared_ptr<std::set<TextQuery::LineNo>> line_nos_ptr_;
  const std::shared_ptr<TextQuery::InputType> file_ptr_;
};

} // namespace cps

#endif
