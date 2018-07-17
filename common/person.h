#ifndef CPS_PERSON_H_
#define CPS_PERSON_H_

#include <iostream>
#include <string>

namespace cps {

class Person {
public:
  // constructors
  Person() = default;
  Person(const std::string &name) : name_(name) {}
  Person(const std::string &name, const std::string &addr)
      : name_(name), address_(addr) {}
  // member functions
  inline std::string name() const { return name_; }
  inline std::string address() const { return address_; }
  std::istream &read(std::istream &);
  std::ostream &print(std::ostream &) const;

private:
  std::string name_;
  std::string address_;
};

inline std::istream &Person::read(std::istream &is) {
  is >> name_ >> address_;
  return is;
}

inline std::ostream &Person::print(std::ostream &os) const {
  os << name_ << ' ' << address_;
  return os;
}

} // namespace cps

#endif
