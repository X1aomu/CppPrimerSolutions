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
      if (str == pre_str) {
        break;
      }
      pre_str = str;
    }
    cout << (str == pre_str ? str : "No word has been repeated!") << endl;
  } else {
    cout << "No word has been repeated!" << endl;
  }
  return 0;
}
