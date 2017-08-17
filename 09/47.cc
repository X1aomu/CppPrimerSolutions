#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
  string numbers("0123456789");
  string str("ab2c3d7R4E6");
  // use find_fisrt_of
  for (string::size_type pos = 0;
       (pos = str.find_first_of(numbers, pos)) != string::npos; ++pos) {
    cout << str[pos];
  }
  cout << endl;
  for (string::size_type pos = 0;
       (pos = str.find_first_of(alphabet, pos)) != string::npos; ++pos) {
    cout << str[pos];
  }
  cout << endl;
  // use find_fisrt_not_of
  // just swap numbers and alphabet
  // ...
  return 0;
}
