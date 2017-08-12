#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

bool str_subrange(const string &str1, const string &str2) {
  if (str1.size() == str2.size())
    return str1 == str2;
  auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
  for (decltype(size) i = 0; i != size; ++i) {
    if (str1[i] != str2[i])
      return false;
  }
  // Here is no return statement, but on my machine it will return true as
  // default.
}

int main() {
  string s1, s2;
  cout << "Input two strings: ";
  cin >> s1 >> s2;
  if (str_subrange(s1, s2)) cout << "One is the other's subset." << endl;
  else cout << "No one is the other's subset." << endl;
  return 0;
}
