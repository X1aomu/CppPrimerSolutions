#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<char> cvec{'a', 'b', 'c', 'd', 'e', 'f', 'g'};
  std::string s(cvec.cbegin(), cvec.cend());
  std::cout << s << std::endl;
  return 0;
}
