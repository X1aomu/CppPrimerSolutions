#include <iostream>

int main() {
  std::cout << "/*";
  std::cout << "*/";
  std::cout << 1 /* "*/;
  std::cout << /* "*/ " /* " /*" */;
  return 0;
}
