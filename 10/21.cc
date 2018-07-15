#include <iostream>

#include "common/person.h"

int main(void) {
  int var;
  std::cin >> var;
  auto ret = [&var]() -> bool {
    --var;
    if (var == 0)
      return true;
    else
      return false;
  };
  while (!ret()) {
    std::cout << var << std::endl;
  }
  return 0;
}
