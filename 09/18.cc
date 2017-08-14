#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::deque<std::string> ds;
  std::string str;
  while (cin >> str) {
    ds.push_back(str);
  }
  for (decltype(ds.cbegin()) it = ds.cbegin(); it != ds.cend(); ++it) {
    cout << *it << endl;
  }
  return 0;
}
