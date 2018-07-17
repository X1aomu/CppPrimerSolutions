#ifndef CPS_CP13_EX27_HAS_PTR_H_
#define CPS_CP13_EX27_HAS_PTR_H_

#include <string>

class HasPtr {
public:
  HasPtr(const std::string &s = std::string())
      : ps_(new std::string(s)), i_(0), use_(new size_t(1)) {}

  ~HasPtr() {
    if (--*use_ == 0) {
      delete ps_;
      delete use_;
    }
  }
  HasPtr(const HasPtr &o) : ps_(new std::string(*o.ps_)), i_(o.i_) {}
  HasPtr &operator=(const HasPtr &rhs) {
    ++*rhs.use_;
    if (--*use_ == 0) {
      delete ps_;
      delete use_;
    }
    ps_ = rhs.ps_;
    i_ = rhs.i_;
    use_ = rhs.use_;
    return *this;
  }

private:
  std::string *ps_;
  int i_;
  size_t *use_;
};

#endif
