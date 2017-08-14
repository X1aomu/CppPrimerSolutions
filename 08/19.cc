#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::list<std::string> ls;
  std::string str;
  while (cin >> str) {
    ls.push_back(str);
  }
  for (decltype(ls.cbegin()) it = ls.cbegin(); it != ls.cend(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
