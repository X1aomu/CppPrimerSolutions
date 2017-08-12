#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

void call_output_ivec(const vector<int> &iv, vector<int>::const_iterator it) {
  if (it != iv.cend()) {
    cout << *it << ' ';
    call_output_ivec(iv, it + 1);
  }
}

void output_ivec(const vector<int> &iv) {
  call_output_ivec(iv, iv.cbegin());
  cout << endl;
}

int main() {
  vector<int> ivec;
  cout << "Input a series of integers: ";
  int temp;
  while (cin >> temp) {
    ivec.push_back(temp);
  }
  output_ivec(ivec);
  return 0;
}
