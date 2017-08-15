#include <iostream>
#include <list>
#include <vector>

int main() {
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
  std::vector<int> ivec;
  std::list<int> ilst;
  for (auto i : ia) {
    ivec.push_back(i);
    ilst.push_back(i);
  }
  for (auto iter = ivec.begin(); iter != ivec.end(); ) {
    if (*iter % 2 == 0) {
      iter = ivec.erase(iter);
    } else {
      ++iter;
    }
  }
  for (auto iter = ilst.begin(); iter != ilst.end(); ) {
    if (*iter % 2 != 0) {
      iter = ilst.erase(iter);
    } else {
      ++iter;
    }
  }
  // output testing
  for (const auto &i : ivec) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  // output testing
  for (const auto &i : ilst) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  return 0;
}
