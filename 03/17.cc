#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> s_vec;
  string temp;
  while (cin >> temp) {
    s_vec.push_back(temp);
  }
  for (auto &s : s_vec) {
    for (auto &c : s) {
      c = toupper(c);
    }
    cout << s << endl;
  }
  return 0;
}
