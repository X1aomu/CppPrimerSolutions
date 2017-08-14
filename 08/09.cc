#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

std::istream &func(std::istream &is) {
  char c;
  while (is >> c) {
    cout << c;
  }
  is.clear();
  return is;
}

int main() {
  std::string str("I need helping!...");
  std::istringstream iss(str);
  func(iss);
  return 0;
}
