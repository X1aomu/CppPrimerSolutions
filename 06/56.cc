#include <exception>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::vector;

int OperateAdd(const int &a, const int &b) { return a + b; }
int OperateSubstract(const int &a, const int &b) { return a - b; }
int OperateMultiple(const int &a, const int &b) { return a * b; }
int OperateDivided(const int &a, const int &b) { return a / b; }

int main() {
  vector<int (*)(const int &, const int &)> func_vec{
      OperateAdd, OperateSubstract, OperateMultiple, OperateDivided};
  int a, b;
  while (cout << "Input two integers: ", cin >> a >> b) {
    try {
      if (b == 0)
        throw runtime_error("ERROR: the second integer must not be zero!");
      for (const auto it : func_vec) {
        cout << (*it)(a, b) << endl; // Output operating result
      }
      break; // while
    } catch (runtime_error err) {
      cout << err.what() << endl;
      cout << "Try again? Input y or n: ";
      char c;
      cin >> c;
      if (!cin || c == 'n')
        break; // while
    }
  }
  return 0;
}
