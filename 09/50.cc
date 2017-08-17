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
  int sum_int = 0;
  double sum_double = 0.0;
  vector<string> svec_int{"00", "10", "11", "42", "22", "44", "37", "73"};
  vector<string> svec_double{"0.0", "1.0", "1.1", "4.2", "2.2", "4.4", "3.7"};
  for (const auto &s : svec_int) {
    sum_int += stoi(s);
  }
  for (const auto &s : svec_double) {
    sum_double += stod(s);
  }
  cout << sum_int << endl << sum_double << endl;
  return 0;
}
