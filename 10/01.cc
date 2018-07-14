#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cout << "Input a sequence of integers: ";
  string line;
  getline(cin, line);
  istringstream buf(line);
  vector<int> ivec;
  int num;
  while (buf >> num) {
    ivec.push_back(num);
  }
  cout << "Input a given integer: ";
  cin >> num;
  cout << count(ivec.cbegin(), ivec.cend(), num) << endl;
}
