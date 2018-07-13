#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Date {
public:
  using Year = unsigned;
  using Month = unsigned;
  using Day = unsigned;
  Date() = default;
  explicit Date(const string &s) { Change(s); }
  std::ostream &Print(std::ostream &os = cout) {
    return os << year_ << '/' << month_ << '/' << day_;
  }
  bool Change(const string &str);
  void set_year(const Year &y) { year_ = y; }
  void set_month(const Month &m) { month_ = m; }
  void set_day(const Day &d) { day_ = d; }

private:
  Year year_ = 2017;
  Month month_ = 8;
  Day day_ = 16;
};

int main() {
  string line;
  while (getline(cin, line)) {
    Date birthday(line);
    birthday.Print() << endl;
  }
  return 0;
}

bool Date::Change(const string &str) {
  bool flag = true;
  const string numbers("0123456789");
  const string spaces(" \t");
  std::map<string, Month> month{
      {"Jan", 1},       {"Feb", 2},      {"Mar", 3},       {"Apr", 4},
      {"May", 5},       {"Jun", 6},      {"Jul", 7},       {"Aug", 8},
      {"Sep", 9},       {"Oct", 10},     {"Nov", 11},      {"Dec", 12},
      {"January", 1},   {"Februray", 2}, {"March", 3},     {"April", 4},
      {"Sept", 9},      {"June", 6},     {"July", 7},      {"August", 8},
      {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}};
  string s = str;
  string str_year, str_month, str_day;
  // delete the prefix spaces
  s = s.substr(s.find_first_not_of(spaces));
  // delete the suffix spaces
  s = s.substr(0, s.find_last_not_of(spaces) + 1);
  if (s.find_first_of(numbers) != 0) {
    // format is Aug(ust) 16, 2017
    auto month_end = s.find_first_of(". "); // exclude "." of "Aug."
    str_month = s.substr(0, month_end);
    if (month.find(str_month) != month.end()) {
      month_ = month[str_month];
    } else {
      flag = false;
    }
  } else {
    // format is 8/16/2017 8.16.2017
    auto first_seperator = s.find_first_not_of(numbers);
    str_month = s.substr(0, first_seperator);
    month_ = stoul(str_month);
    s = s.substr(first_seperator); // cut the first number.
  }
  auto day_start = s.find_first_of(numbers);
  auto day_end = s.find_first_not_of(numbers);
  auto year_start = s.find_last_not_of(numbers) + 1;
  str_day = s.substr(day_start, day_end - day_start);
  str_year = s.substr(year_start, s.size() - year_start);
  year_ = std::stoul(str_year);
  day_ = std::stoul(str_day);
  if (month_ > 12 || day_ > 31)
    flag = false;
  if (!flag)
    cerr << "ERROR: " << str << " wrong date format! Set as default." << endl;
  return flag;
}
