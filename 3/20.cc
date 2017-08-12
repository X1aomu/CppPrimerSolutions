#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;

int main() {
  vector<int> ivec;
  int itemp;
  while (cin >> itemp) {
    ivec.push_back(itemp);
  }
  for (decltype(ivec.size()) index = 0; index < ivec.size() - 1; ++index) {
    cout << ivec[index] + ivec[index + 1] << endl;
  }
  for (decltype(ivec.size()) index = 0; index < ivec.size() - index; ++index) {
    cout << ivec[index] + ivec[ivec.size() - index - 1] << endl;
  }
  return 0;
}
