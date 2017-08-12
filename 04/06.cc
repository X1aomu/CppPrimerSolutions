#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
  int num;
  cout << "Input a number: ";
  cin >> num;
  if (num % 2 == 0)
    cout << num << " is an even number." << endl;
  else
    cout << num << " is an odd number." << endl;
  return 0;
}
