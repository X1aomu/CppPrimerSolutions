#ifndef CPS_CP13_EX30_HAS_PTR_H_
#define CPS_CP13_EX30_HAS_PTR_H_

#include <string>
#include <utility>

class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

public:
  HasPtr(const std::string &s = std::string())
      : ps_(new std::string(s)), i_(0) {}

  ~HasPtr() { delete ps_; }
  HasPtr(const HasPtr &o) : ps_(new std::string(*o.ps_)), i_(o.i_) {}
  HasPtr &operator=(const HasPtr &rhs) {
    auto newp = new std::string(*rhs.ps_);
    delete ps_;
    ps_ = newp;
    i_ = rhs.i_;
    return *this;
  }

private:
  std::string *ps_;
  int i_;
};

inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps_, rhs.ps_);
  swap(lhs.i_, rhs.i_);
}

#endif
