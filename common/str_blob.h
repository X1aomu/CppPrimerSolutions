#ifndef CPS_STR_BLOB_H_
#define CPS_STR_BLOB_H_

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace cps {

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend class ConstStrBlobPtr;

public:
  using size_type = std::vector<std::string>::size_type;

  StrBlob() : data_(std::make_shared<std::vector<std::string>>()) {}
  StrBlob(std::initializer_list<std::string> il)
      : data_(std::make_shared<std::vector<std::string>>(il)) {}

  size_type size() const { return data_->size(); }

  bool empty() const { return data_->empty(); }

  void push_back(const std::string &t) { data_->push_back(t); }
  // added for ex13.55 in section 13.6.3
  void push_back(std::string &&t) { data_->push_back(std::move(t)); }
  void pop_back() {
    check(0, "pop_back on empty StrBlob");
    data_->pop_back();
  }

  std::string &front() {
    check(0, "front on empty StrBlob");
    return data_->front();
  }
  const std::string &front() const {
    check(0, "front on empty StrBlob");
    return data_->front();
  }

  std::string &back() {
    check(0, "back on empty StrBlob");
    return data_->back();
  }
  const std::string &back() const {
    check(0, "back on empty StrBlob");
    return data_->back();
  }

  StrBlobPtr begin();
  StrBlobPtr end();

  ConstStrBlobPtr cbegin() const; // add const here
  ConstStrBlobPtr cend() const;   // add const here

private:
  std::shared_ptr<std::vector<std::string>> data_;

  void check(size_type i, const std::string &msg) const {
    if (i > data_->size())
      throw std::out_of_range(msg);
  }
};

class StrBlobPtr {
public:
  StrBlobPtr() : curr_(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr_(a.data_), curr_(sz) {}

  bool operator!=(const StrBlobPtr &p) { return curr_ != p.curr_; }

  std::string &deref() const {
    auto p = check(curr_, "dereference past end");
    return (*p)[curr_];
  }

  StrBlobPtr &incr() {
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
  }

private:
  std::weak_ptr<std::vector<std::string>> wptr_;
  std::size_t curr_;

  std::shared_ptr<std::vector<std::string>>
  check(std::size_t i, const std::string &msg) const {
    auto ret = wptr_.lock();
    if (!ret)
      throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
      throw std::out_of_range(msg);
    return ret;
  }
};

class ConstStrBlobPtr {
public:
  ConstStrBlobPtr() : curr_(0) {}
  // add const here
  ConstStrBlobPtr(const StrBlob &a, size_t sz = 0)
      : wptr_(a.data_), curr_(sz) {}

  bool operator!=(const ConstStrBlobPtr &p) { return curr_ != p.curr_; }

  // add const here
  const std::string &deref() const {
    auto p = check(curr_, "dereference past end");
    return (*p)[curr_];
  }

  ConstStrBlobPtr &incr() {
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
  }

private:
  std::weak_ptr<std::vector<std::string>> wptr_;
  std::size_t curr_;

  std::shared_ptr<std::vector<std::string>>
  check(std::size_t i, const std::string &msg) const {
    auto ret = wptr_.lock();
    if (!ret)
      throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
      throw std::out_of_range(msg);
    return ret;
  }
};

} // namespace cps

#endif
