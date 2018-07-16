#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
  char cs1[] = "Write a program to concatenate two string literals, ";
  char cs2[] = "putting the result in a dynamically allocated array of char.";
  char *concat_string = new char[strlen(cs1) + strlen(cs2) + 1];
  strcpy(concat_string, cs1);
  strcat(concat_string, cs2);
  cout << concat_string << endl;
  delete[] concat_string;

  string s1(cs1);
  string s2(cs2);
  cout << s1 + s2 << endl;

  return 0;
}
