#include <iostream>
#include <memory>
#include <vector>

using namespace std;

shared_ptr<vector<int>> Allocate() { return make_shared<vector<int>>(); }

void ReadInput(vector<int> &ivec) {
  int num;
  while (cin >> num) {
    ivec.push_back(num);
  }
}

void Print(const vector<int> &ivec) {
  for (auto num : ivec) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  auto vec_ptr = Allocate();
  ReadInput(*vec_ptr);
  Print(*vec_ptr);
  return 0;
}
