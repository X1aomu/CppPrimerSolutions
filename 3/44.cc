#include <iostream>
#include <iterator>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::begin;
using std::end;

using int_array_2d = int[3][4];
using int_array = int[4];

int main() {
  int_array_2d ia = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  for (int_array &p : ia) {
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
  for (int_array *prow = begin(ia); prow != end(ia); ++prow) {
    for (int *p = begin(*prow); p != end(*prow); ++p) {
      cout << *p << ' ';
    }
    cout << endl;
  }
  return 0;
}
