#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
  int a, b;  // a / b
  cout << "Input two integers: ";
  cin >> a >> b;
  if (b == 0)
    throw std::runtime_error("Divisor must not be zero!");
  cout << a / b << endl;
  return 0;
}
