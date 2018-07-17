#ifndef CPS_TEXT_QUERY_H_
#define CPS_TEXT_QUERY_H_

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>

namespace cps {

class QueryResult;

class TextQuery {
public:
  using InputType = std::vector<std::string>;
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

  std::set<TextQuery::LineNo>::iterator begin() const;
  std::set<TextQuery::LineNo>::iterator end() const;

  std::shared_ptr<TextQuery::InputType> get_file() const;

private:
  std::string word_;
  std::shared_ptr<std::set<TextQuery::LineNo>> line_nos_ptr_;
  std::shared_ptr<TextQuery::InputType> file_ptr_;
};

} // namespace cps

#endif
