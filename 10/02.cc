#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cout << "Input a sequence of string: ";
  string line;
  getline(cin, line);
  istringstream buf(line);
  vector<string> ivec;
  string str;
  while (buf >> str) {
    ivec.push_back(str);
  }
  cout << "Input a given string: ";
  cin >> str;
  cout << count(ivec.cbegin(), ivec.cend(), str) << endl;
}
