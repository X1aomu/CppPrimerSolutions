#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void func(std::vector<std::string> &vec, std::ifstream &is) {
  std::string str;
  while (is >> str) {
    vec.push_back(str);
  }
}

int main() {
  const std::string file_input("data/04");
  std::ifstream input(file_input);
  std::vector<std::string> vec;
  if (input) {
    func(vec, input);
  } else {
    std::cerr << file_input << ": file not found!" << std::endl;
  }
  // testing
  for (auto s : vec) {
    std::cout << s << ' ';
  }
  std::cout << std::endl;
  return 0;
}
