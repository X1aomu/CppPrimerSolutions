#include <iostream>

std::istream &func(std::istream &is) {
  char c;
  while (is >> c) {
    std::cout << c;
  }
  is.clear();
  return is;
}

int main() {
  std::string cin_true = "cin is true", cin_false = "cin is false";
  std::cout << (std::cin ? cin_true : cin_false) << std::endl;
  func(std::cin);
  std::cout << (std::cin ? cin_true : cin_false) << std::endl;
  return 0;
}
