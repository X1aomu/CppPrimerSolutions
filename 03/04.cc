#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  if (str1 == str2) {
    cout << "str1 is equal to str2" << endl;
  } else {
    cout << "The greater one is: " << (str1 > str2 ? str1 : str2) << endl;
    cout << "The longer one is: " << (str1.size() > str2.size() ? str1 : str2)
         << endl;
  }
  return 0;
}
