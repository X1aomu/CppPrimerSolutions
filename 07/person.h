#include <iostream>
#include <string>

class Person {
 public:
  // constructors
  Person() = default;
  Person(const std::string &name): _name(name) {}
  Person(const std::string &name, const std::string &addr)
      : _name(name), _address(addr) {}
  // member functions
  inline std::string name() const { return _name; }
  inline std::string address() const { return _address; }
  std::istream &read(std::istream &);
  std::ostream &print(std::ostream &) const;
 private:
  std::string _name;
  std::string _address;
};

inline std::istream &Person::read(std::istream &is) {
  is >> _name >> _address;
  return is;
}

inline std::ostream &Person::print(std::ostream &os) const {
  os << _name << ' ' <<  _address;
  return os;
}
