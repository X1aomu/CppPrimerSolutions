#include <iostream>
#include <string>

using std::string;

class Person {
public:
  string name() const { return _name; };
  string address() const { return _address; };

private:
  string _name;
  string _address;
};

int main() { return 0; }
