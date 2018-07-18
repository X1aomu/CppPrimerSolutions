// This file is inspired by
// https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch13/13.43/13.43.cpp
#include "common/str_vec.h"

#include <iostream>

using cps::StrVec;
using std::cout;
using std::endl;

void print(const StrVec &sv) {
  cout << "size: " << sv.size() << " capacity: " << sv.capacity()
       << " elements:";
  for (size_t i = 0; i != sv.size(); ++i) {
    cout << " " << sv.at(i);
  }
  cout << endl;
}

int main() {
  StrVec sv;
  print(sv);

  sv.push_back("s1");
  print(sv);
  sv.push_back("s2");
  print(sv);
  sv.push_back("s3");
  print(sv);
  sv.push_back("s4");
  print(sv);
  sv.push_back("s5");
  print(sv);

  {
    StrVec sv2(sv);
    print(sv2);
    sv2.push_back("s6");
    print(sv);
    print(sv2);
    // sv.pop_back();
    print(sv);
    print(sv2);
    sv = sv2;
    print(sv);
    print(sv2);
  }

  sv.reserve(sv.capacity() / 2);
  print(sv);
  sv.reserve(sv.capacity() * 2);
  print(sv);

  sv.resize(sv.size() + 2);
  print(sv);
  // sv.resize(sv.size() + 2, "s7");
  print(sv);
  sv.resize(sv.size() - 2);
  print(sv);
  // sv.resize(sv.size() - 2, "s7");
  print(sv);

  StrVec sv2{"il1", "il2", "il3", "il4", "il5"};
  print(sv2);
  StrVec sv3 = {"il1", "il2", "il3", "il4", "il5"};
  print(sv3);

  return 0;
}
