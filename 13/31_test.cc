#include "13/31_has_ptr.h"

#include <algorithm>
#include <iostream>
#include <vector>

using cps::HasPtr;
using std::vector;

int main() {
  vector<HasPtr> vec;
  vec.push_back(HasPtr("ex_13_31"));
  vec.push_back(HasPtr("ex_13_11"));
  vec.push_back(HasPtr("ex_13_13"));
  vec.push_back(HasPtr("ex_13_33"));
  vec.push_back(HasPtr("ex_13_00"));
  std::sort(vec.begin(), vec.end());

  std::cout << "Complied and run successfully!" << std::endl;

  return 0;
}
