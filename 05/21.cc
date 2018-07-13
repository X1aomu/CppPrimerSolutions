#include <cctype>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string pre_str, str;
  if (cin >> pre_str) {
    while (cin >> str) {
      if (str == pre_str && isupper(str[0])) {
        break;
      }
      pre_str = str;
    }
    cout << ((str == pre_str && isupper(str[0])) ? str : "No match!") << endl;
  } else {
    cout << "No match!" << endl;
  }
  return 0;
}
