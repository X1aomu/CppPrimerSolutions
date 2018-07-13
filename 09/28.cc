#include <forward_list>
#include <iostream>
#include <string>

using StringList = std::forward_list<std::string>;

StringList::iterator ListInsertAfterString(StringList &list,
                                           const std::string &to_find,
                                           const std::string &str) {
  StringList::iterator prev = list.before_begin(), curr = list.begin();
  while (curr != list.end()) {
    if (*curr != to_find) {
      ++prev;
      ++curr;
    } else {
      ++prev;
      ++curr;
      break;
    }
  }
  return curr = list.insert_after(prev, str);
}

int main() {
  StringList slst;
  std::string str;
  auto prev = slst.before_begin(), curr = slst.begin();
  std::cout << "Input some strings below, end up with EOF:" << std::endl;
  while (std::cin >> str) {
    prev = curr = slst.insert_after(prev, str);
    ++curr;
  }
  std::cin.clear();
  std::string to_find;
  std::cout << "Input the string to insert after:" << std::endl;
  std::cin >> to_find;
  std::cout << "Input the string to insert:" << std::endl;
  std::cin >> str;
  ListInsertAfterString(slst, to_find, str);
  for (const auto &s : slst) {
    std::cout << s << ' ';
  }
  std::cout << std::endl;
  return 0;
}
