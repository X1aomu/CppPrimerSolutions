#include <deque>
#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main() {
  std::list<int> i_list;
  std::deque<int> dq1, dq2;
  int temp;
  while (cin >> temp) {
    i_list.push_back(temp);
  }
  decltype(i_list.cbegin()) it = i_list.cbegin();
  while (it != i_list.cend()) {
    dq1.push_back(*it);
    ++it;
    dq2.push_back(*it);
    ++it;
  }
  // print
  for (const auto &i : dq1) {
    cout << i << ' ';
  }
  cout << endl;
  for (const auto &i : dq2) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
