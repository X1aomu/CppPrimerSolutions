#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // This program handles varying size inputs by using std::string. Thus no more
  // job to do here
  string s;
  cin >> s;
  char *cs = new char[s.length() + 1];
  strcpy(cs, s.c_str());
  cout << cs << endl;
  delete[] cs;
  return 0;
}
