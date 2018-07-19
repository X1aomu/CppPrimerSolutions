#include "13/47_string.h"

#include <iostream>
#include <vector>

using namespace std;
using cps::String;

int main() {
  cout << "initialize svec0 by default constructor" << endl;
  vector<String> svec0;
  cout << endl;

  int n = 20;
  while (n--) {
    cout << "push back svec0"
         << " size(before push back)=" << svec0.size() << endl;
    svec0.push_back("this is a string");
  }
  cout << endl;

  cout << "define svec1 and assign svec0 to it" << endl;
  auto svec1 = svec0;
  cout << endl;

  cout << "initialize svec2 by copy constructor(passed svec1)" << endl;
  vector<String> svec2(svec1);
  cout << endl;

  cout << "assign svec0 to svec2" << endl;
  svec2 = svec0;
  cout << endl;

  cout << "assign svec1 to svec2" << endl;
  svec2 = svec1;
  cout << endl;

  return 0;
}
