#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string GenName(string name, const string &prefix, const string &suffix) {
  if (prefix.size()) {
    name.insert(0, prefix + ' ');
  }
  if (suffix.size()) {
    name.insert(name.size(), ' ' + suffix);
  }
  return name;
}

int main() {
  cout << GenName("Gray", "Mr.", "Ⅱ") << endl;
  return 0;
}
