#include <iostream>
#include "screen.h"

using std::cout;
using std::endl;

int main() {
  class Screen my_screen(5, 5, 'X');
  my_screen.Move(4, 0).Set('#').Display(cout);
  cout << endl;
  my_screen.Display(cout);
  cout << endl;
  return 0;
}
