#ifndef CPS_STRING_H_
#define CPS_STRING_H_

#include <algorithm> // std::for_each
#include <iostream>
#include <memory>  // std::allocator
#include <utility> // std::move

namespace cps {

class String {
public:
  using size_type = size_t;

public:
  String() : String("") {}
  String(const char *c);

  ~String();
  String(const String &);
  String &operator=(const String &);
  String(String &&) noexcept;
  String &operator=(String &&) noexcept;

  String &operator+=(const String &);

  const char *c_str() const { return c_; }

  char *begin() { return c_; }
  char *end() { return end_; }
  const char *cbegin() const { return c_; }
  const char *cend() const { return end_; }

  size_t length() const { return end_ - c_ - 1; }
  size_t capacity() const { return cap_ - c_; }
  void reserve(const size_t &n);
  void resize(const size_t &size, const char &c = char());

private:
  static std::allocator<char> alloc_;

  char *c_;
  char *end_;
  char *cap_;

  size_t size() const { return end_ - c_; }

  std::pair<char *, char *> alloc_n_copy(const char *b, const char *e);
  void reallocate();
  void free();
};

String operator+(const String &left, const String &right);

bool operator==(const String &left, const String &right);
bool operator!=(const String &left, const String &right);
bool operator<(const String &left, const String &right);
bool operator>(const String &left, const String &right);
bool operator<=(const String &left, const String &right);
bool operator>=(const String &left, const String &right);

/**********************************
 * constructors
 **********************************/

inline String::String(const char *c) {
  const char *begin = c;
  const char *end = c;
  while (*end++ != '\0') {
    /* empty */
  }

  auto newdata = alloc_n_copy(begin, end);
  c_ = newdata.first;
  end_ = cap_ = newdata.second;
}

/**********************************
 * copy control
 **********************************/

inline String::~String() { free(); }

inline String::String(const String &s) {
  std::cout << "Calling copy constructor ..." << std::endl; // add for ex13.47
  auto newdata = alloc_n_copy(s.cbegin(), s.cend());
  c_ = newdata.first;
  end_ = cap_ = newdata.second;
}

inline String &String::operator=(const String &rhs) {
  std::cout << "Calling assignment function ..."
            << std::endl; // add for ex13.47
  auto newdata = alloc_n_copy(rhs.cbegin(), rhs.cend());
  free(); // free old data
  c_ = newdata.first;
  end_ = cap_ = newdata.second;
  return *this;
}

inline String::String(String &&s) noexcept
    : c_(s.c_), end_(s.end_), cap_(s.cap_) {
  std::cout << "calling moving constructor ..." << std::endl;
  s.c_ = s.end_ = s.cap_ = nullptr;
}

inline String &String::operator=(String &&rhs) noexcept {
  if (this != &rhs) {
    std::cout << "calling moving assignment function ..." << std::endl;
    c_ = rhs.c_;
    end_ = rhs.end_;
    cap_ = rhs.cap_;
    rhs.c_ = rhs.end_ = rhs.cap_ = nullptr;
  }
  return *this;
}

/**********************************
 * public members
 **********************************/

inline void String::reserve(const size_t &n) {
  while (capacity() < n) {
    reallocate();
  }
}

inline void String::resize(const size_t &newsize, const char &c) {
  auto new_end = c_ + newsize;

  if (new_end < end_) {
    while (end_-- != new_end) {
      alloc_.destroy(end_);
    }
  } else {
    reserve(newsize);
    while (end_ != new_end) {
      alloc_.construct(end_++, c);
    }
  }
}

/**********************************
 * private members
 **********************************/

inline void String::free() {
  // may not pass deallocate() null pointer
  if (c_) {
    std::for_each(c_, end_, [](char &c) { alloc_.destroy(&c); });

    alloc_.deallocate(c_, end_ - c_);
  }
}

inline std::pair<char *, char *> String::alloc_n_copy(const char *b,
                                                      const char *e) {
  // allocate space to hold as many elements as are in the range
  auto data = alloc_.allocate(e - b);

  // initialize and return a pair constructed from data and
  // the value returned by uninitialized_copy
  return {data, std::uninitialized_copy(b, e, data)};
}

inline void String::reallocate() {
  auto newcapacity = size() ? size() * 2 : 1;
  auto newdata = alloc_.allocate(newcapacity);
  auto dest = newdata;
  auto src = c_;

  for (size_t i = 0; i != size(); ++i) {
    alloc_.construct(dest++, std::move(*src++));
  }
  free();

  c_ = newdata;
  end_ = dest;
  cap_ = newdata + newcapacity;
}

} // namespace cps

#endif
