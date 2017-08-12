#include "Sales_item.h"
#include <iostream>

int main() {
  Sales_item book;
  while (std::cin >> book) {
    std::cout << book << std::endl;
  }
  return 0;
}
