#include "12/22_const_str_blob_ptr.h"

#include <iostream>

int main() {
  cps::StrBlob msg({});
  msg.push_back("What changes would need to be made to StrBlobPtr to create a "
                "class that can be used with a const StrBlob?");
  msg.push_back("Define a class named ConstStrBlobPtr that can point to a "
                "const StrBlob.");

  const cps::StrBlob msg_const = msg;
  for (auto cp = msg_const.cbegin(); cp != msg_const.cend(); cp.incr()) {
    std::cout << cp.deref() << std::endl;
  }
}
