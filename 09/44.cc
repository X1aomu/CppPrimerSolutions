#include <iostream>
#include <string>

using std::string;

void ReplaceString(string &s, const string &old_val, const string &new_val) {
  auto old_size = old_val.size();
  if (s.size() && old_size && old_size <= s.size()) {
    // search from replace_start to end_of_start - 1
    string::size_type replace_start = 0;
    decltype(replace_start) end_of_start = s.size() - old_size + 1;
    while (replace_start != end_of_start) {
      if (s.substr(replace_start, old_size) != old_val) {
        ++replace_start;
      } else {
        s.replace(replace_start, old_size, new_val);
        break;
      }
    }
  }
}

int main() {
  string s = "C++";
  ReplaceString(s, "C++", "C++ Primer");
  std::cout << s << std::endl;
  ReplaceString(s, "Primer", "Primer Fifth");
  std::cout << s << std::endl;
  ReplaceString(s, "Fifth", "Fifth Edition");
  std::cout << s << std::endl;
  ReplaceString(s, "Fifth", "5th");
  std::cout << s << std::endl;
  return 0;
}
