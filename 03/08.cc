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
  string str2 = str;
  decltype(str.size()) index = 0;
  while (index < str.size()) {
    str[index] = 'X';
    ++index;
  }
  cout << str << endl;
  for (decltype(str2.size()) i = 0; i < str2.size(); ++i) {
    str2[i] = 'X';
  }
  cout << str2 << endl;
  return 0;
}
