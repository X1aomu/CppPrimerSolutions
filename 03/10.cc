#include <cctype>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string str, temp;
  cin >> temp;
  for (const auto &c : temp) {
    if (!ispunct(c))
      str += c;
  }
  cout << str << endl;
  return 0;
}
