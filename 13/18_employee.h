#ifndef CPS_CP13_EX18_H_
#define CPS_CP13_EX18_H_

#include <string>

class Employee {
public:
  Employee() : id_(++max_id_), name_(std::string()) {}
  Employee(std::string name) : id_(++max_id_), name_(name) {}

private:
  static unsigned long max_id_;

  unsigned long id_;
  std::string name_;
};

#endif
