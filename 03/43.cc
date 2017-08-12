#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::begin;
using std::end;

int main() {
  int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  for (int (&p)[4] : ia) {
    for (int &q : p) {
      cout << q << ' ';
    }
    cout << endl;
  }
  for (int i = 0; i != 3; ++i) {
    for (int j = 0; j != 4; ++j) {
      cout << ia[i][j] << ' ';
    }
    cout << endl;
  }
  for (int (*prow)[4] = begin(ia); prow != end(ia); ++prow) {
    for (int *p = begin(*prow); p != end(*prow); ++p) {
      cout << *p << ' ';
    }
    cout << endl;
  }
  return 0;
}
