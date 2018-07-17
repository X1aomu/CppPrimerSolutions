#ifndef CPP_PRIMER_CP13_EX19_H_
#define CPP_PRIMER_CP13_EX19_H_

#include <string>

class Employee {
public:
  Employee() : id_(++max_id_), name_(std::string()) {}
  Employee(std::string name) : id_(++max_id_), name_(name) {}

  Employee(const Employee &) = delete;
  Employee &operator=(const Employee &) = delete;

private:
  static unsigned long max_id_;

  unsigned long id_;
  std::string name_;
};

#endif
