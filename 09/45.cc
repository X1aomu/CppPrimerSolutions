#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string GenName(string name, const string &prefix, const string &suffix) {
  if (prefix.size()) {
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.cbegin(), prefix.cend());
  }
  if (suffix.size()) {
    name.append(' ' + suffix);
  }
  return name;
}

int main() {
  cout << GenName("Gray", "Mr.", "Ⅱ") << endl;
  return 0;
}
