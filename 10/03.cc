#include <algorithm>
#include <iostream>
#include <numeric>
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
  cout << accumulate(ivec.cbegin(), ivec.cend(), 0) << endl;
}
