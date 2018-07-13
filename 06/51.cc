#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::clog;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void f() {
#ifndef NDEBUG
  clog << "Calling f()." << endl;
#endif
}

void f(int a) {
#ifndef NDEBUG
  clog << "Calling f(int)." << endl;
#endif
}

void f(int a, int b) {
#ifndef NDEBUG
  clog << "Calling f(int, int)." << endl;
#endif
}

void f(double a, double b = 3.14) {
#ifndef NDEBUG
  clog << "Calling f(double, double = 3.14)." << endl;
#endif
}

int main() {
  // f(2.56, 42);  // This calling is ambiguous.
  f(42);
  f(42, 0);
  f(2.56, 3.14);
  return 0;
}
