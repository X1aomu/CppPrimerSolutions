#include <iostream>
#include <iterator>

using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;

int main() {
  int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  for (auto &p : ia) {
    for (auto &q : p) {
      cout << q << ' ';
    }
    cout << endl;
  }
  for (auto i = 0; i != 3; ++i) {
    for (auto j = 0; j != 4; ++j) {
      cout << ia[i][j] << ' ';
    }
    cout << endl;
  }
  for (auto prow = begin(ia); prow != end(ia); ++prow) {
    for (auto p = begin(*prow); p != end(*prow); ++p) {
      cout << *p << ' ';
    }
    cout << endl;
  }
  return 0;
}
