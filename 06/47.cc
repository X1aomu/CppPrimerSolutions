#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::clog;
using std::cout;
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
#ifndef NDEBUG
  clog << "NOTICE:" << __FILE__ << " : in function " << __func__ << " :\n";
  clog << '\t' << "The number of input integers is " << iv.size() << ".\n";
#endif
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
