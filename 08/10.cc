#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
  const std::string file_input("data/10.txt");
  std::ifstream input(file_input);
  std::vector<std::string> vec;
  if (input) {
    std::string line;
    while (getline(input, line)) {
      vec.push_back(line);
    }
    for (auto s : vec) {
      std::istringstream iss(s);
      std::string word;
      while (iss >> word) {
        // testing
        std::cout << word << ' ';
      }
    }
  } else {
    std::cerr << file_input << ": file not found!" << std::endl;
  }
  return 0;
}
