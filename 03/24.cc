#include <iostream>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  vector<int> ivec;
  int itemp;
  while (cin >> itemp) {
    ivec.push_back(itemp);
  }
  for (auto iter = ivec.cbegin(); iter != (ivec.cend() - 1); ++iter) {
    cout << *iter + *(iter + 1) << endl;
  }
  for (auto iter = ivec.cbegin(); iter < ivec.cend() - (iter - ivec.cbegin());
       ++iter) {
    cout << *iter + *(ivec.cend() - (iter - ivec.cbegin()) - 1) << endl;
  }
  return 0;
}
