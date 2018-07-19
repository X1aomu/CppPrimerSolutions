#ifndef CPS_STR_VEC_H_
#define CPS_STR_VEC_H_

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

namespace cps {

class StrVec {
public:
  using size_type = size_t;

public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(std::initializer_list<std::string> /* il */); // added for ex13.40

  ~StrVec();
  StrVec(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec &operator=(const StrVec &);
  StrVec &operator=(StrVec &&) noexcept;

  void push_back(const std::string & /* a string */);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; };

  std::string &at(const size_t &pos) { return *(elements + pos); }
  const std::string &at(const size_t &pos) const { return *(elements + pos); }

  void reserve(const size_t &n);                            // added for ex13.39
  void resize(const size_t &size);                          // added for ex13.39
  void resize(const size_t &size, const std::string &fill); // added for ex13.39

private:
  static std::allocator<std::string> alloc;

  void chk_n_alloc() {
    if (size() == capacity())
      reallocate();
  }
  std::pair<std::string *, std::string *>
  alloc_n_copy(const std::string * /* begin */, const std::string * /* end */);
  void free();
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

inline StrVec::StrVec(std::initializer_list<std::string> il) {
  auto newdata = alloc_n_copy(il.begin(), il.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

inline StrVec::~StrVec() { free(); }
inline StrVec::StrVec(const StrVec &sv) {
  auto newdata = alloc_n_copy(sv.begin(), sv.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}
inline StrVec &StrVec::operator=(const StrVec &rhs) {
  auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
  free(); // free old data
  elements = newdata.first;
  first_free = cap = newdata.second;
  return *this;
}
inline StrVec::StrVec(StrVec &&sv) noexcept
    : elements(sv.elements), first_free(sv.first_free), cap(sv.cap) {
  sv.elements = sv.first_free = sv.cap = nullptr;
}
inline StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
  if (this != &rhs) {
    free();
    elements = rhs.elements;
    first_free = rhs.first_free;
    cap = rhs.cap;
    rhs.elements = rhs.first_free = rhs.cap = nullptr;
  }
  return *this;
}

inline void StrVec::push_back(const std::string &s) {
  chk_n_alloc(); // ensure there is a room for the new element
  alloc.construct(first_free++, s);
}

inline std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
  // allocate space to hold as many elements as are in the range
  auto data = alloc.allocate(e - b);

  // initialize and return a pair constructed from data and
  // the value returned by uninitialized_copy
  return {data, uninitialized_copy(b, e, data)};
}

inline void StrVec::free() {
  // may not pass deallocate() null pointer
  if (elements) {
    //// destroy the old elements in reverse order
    // for (auto p = first_free; p != elements; /* empty */) {
    //  alloc.destroy(--p);
    // }

    // rewrite here for ex13.43
    std::for_each(elements, first_free,
                  [](std::string &s) { alloc.destroy(&s); });

    alloc.deallocate(elements, cap - elements);
  }
}

inline void StrVec::reallocate() {
  auto newcapacity = size() ? size() * 2 : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;

  for (size_t i = 0; i != size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();

  elements = newdata;
  first_free = dest;
  cap = newdata + newcapacity;
}

inline void StrVec::reserve(const size_t &n) {
  while (capacity() < n) {
    reallocate();
  }
}

inline void StrVec::resize(const size_t &newsize) {
  auto new_first_free = elements + newsize;

  if (new_first_free < first_free) {
    while (first_free-- != new_first_free) {
      alloc.destroy(first_free);
    }
  } else {
    reserve(newsize);
    while (first_free != new_first_free) {
      alloc.construct(first_free++);
    }
  }
}

inline void StrVec::resize(const size_t &newsize, const std::string &fill) {
  auto new_first_free = elements + newsize;

  if (new_first_free < first_free) {
    while (first_free-- != new_first_free) {
      alloc.destroy(first_free);
    }
  } else {
    reserve(newsize);
    while (first_free != new_first_free) {
      alloc.construct(first_free++, fill);
    }
  }
}

} // namespace cps

#endif
