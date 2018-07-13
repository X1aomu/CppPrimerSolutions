#include <cctype>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string str;
  cin >> str;
  for (auto &c : str) {
    c = 'X';
  }
  cout << str << endl;
  return 0;
}
