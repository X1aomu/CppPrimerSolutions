#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  vector<int> iv;
  for (int temp; cin >> temp; ) {
    iv.push_back(temp);
  }
  vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
  while (iter != mid) {
    const int some_val = 42;
    if (*iter == some_val) {
      iter = iv.insert(iter, 2 * some_val);
    }
    mid = iv.begin() + iv.size() / 2;
    ++iter;
  }
  // output testing
  for (const auto &i : iv) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
