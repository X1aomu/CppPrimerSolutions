#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::string;

class Person {
 public:
  Person() = default;
  Person(const string &name): _name(name) {};
  Person(const string &name, const string &addr): _name(name), _address(addr) {};
  string name() const { return _name; };
  string address() const { return _address; };
  istream &read(istream &);
  ostream &print(ostream &) const;
 private:
  string _name;
  string _address;
};

int main() {
  return 0;
}

istream & Person::read(istream &is) {
  is >> _name >> _address;
  return is;
}
ostream & Person::print(ostream &os) const {
  os << _name << ' ' <<  _address;
  return os;
}
