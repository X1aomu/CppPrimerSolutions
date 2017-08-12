#include <iostream>
#include <stdexcept>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
  int a, b; // a / b
  while (cout << "Input two integers: ", cin >> a >> b) {
    try {
      if (b == 0)
        throw std::runtime_error("The divisor must not be zero!");
      cout << a / b << endl;
      break;  // If input is valid, it will only execute once.
    } catch (std::runtime_error rt_err) {
      cout << rt_err.what() << endl << "Try again? Enter y or n: ";
      char c;
      cin >> c;
      if (!cin || c == 'n')
        break;
    }
  }
  return 0;
}
