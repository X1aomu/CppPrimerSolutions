#include <iostream>
#include <memory>

using namespace std;

int main() {
  unique_ptr<int> p1(new int(1));
  unique_ptr<int> p2(new int(2));
  /*
  // overload resolution selected deleted operator '='
  p1 = p2;
  // call to a deleted constructor of 'unique_prt<int>'
  unique_ptr<int> p3(p1);
  */
  return 0;
}
