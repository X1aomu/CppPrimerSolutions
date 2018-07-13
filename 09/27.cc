#include <forward_list>
#include <iostream>
#include <vector>

int main() {
  std::forward_list<int> ilst;
  for (int i; std::cin >> i;) {
    ilst.push_front(i); // reverse insertion
  }
  for (auto prev = ilst.before_begin(), curr = ilst.begin();
       curr != ilst.end();) {
    if (*curr % 2 == 1) {
      curr = ilst.erase_after(prev);
    } else {
      ++prev;
      ++curr;
    }
  }
  // output testing
  for (const auto &i : ilst) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
  return 0;
}
