#include <cctype>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main() {
  string upper_str, cat_str, temp;
  cin >> temp;
  upper_str = cat_str = temp;
  while (cin >> temp) {
    upper_str += temp;
    cat_str = cat_str + " " + temp;
  }
  for (auto &c : upper_str) {
    c = toupper(c);
  }
  cout << upper_str << endl;
  cout << cat_str << endl;
  return 0;
}
