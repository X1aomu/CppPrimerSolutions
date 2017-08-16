#include <iostream>
#include <string>

using std::string;

void ReplaceString(string &s, const string &old_val, const string &new_val) {
  auto old_size = old_val.size();
  if (s.size() && old_size && old_size <= s.size()) {
    // search from beg to end_of_begin - 1
    auto beg = s.begin();
    auto end_of_begin = s.end() - old_size + 1;
    while (beg != end_of_begin) {
      if (string(beg, beg + old_size) != old_val) {
        ++beg;
      } else {
        s.erase(beg, beg + old_size);
        s.insert(beg, new_val.cbegin(), new_val.cend());
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
