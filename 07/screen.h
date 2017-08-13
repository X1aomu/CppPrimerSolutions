#include <iostream>
#include <string>

class Screen {
 public:
  using pos = std::string::size_type;
  // constructors
  Screen() = default;
  Screen(pos ht, pos wd) : _height(ht), _width(wd), _contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : _height(ht), _width(wd), _contents(ht * wd, c) {}
  // member functions
  char Get() const;
  char Get(const pos &ht, const pos &wd) const;
  Screen &Move(const pos &r, const pos &c);
  Screen &Set(const char &c);
  Screen &Set(const pos &row, const pos &col, const char &c);
  Screen &Display(std::ostream &os);
  const Screen &Display(std::ostream &os) const;

 private:
  pos _cursor = 0;
  pos _height = 0;
  pos _width = 0;
  std::string _contents;

  void _DoDisplay(std::ostream &os) const;
};

inline char Screen::Get() const {
  return _contents[_cursor];
}
inline char Screen::Get(const pos &ht, const pos &wd) const {
  return _contents[ht * _width + wd];
}
inline Screen &Screen::Move(const pos &r, const pos &c) {
  _cursor = r * _width + c;
  return *this;
}
inline Screen &Screen::Set(const char &c) {
  _contents[_cursor] = c;
  return *this;
}
inline Screen &Screen::Set(const pos &row, const pos &col, const char &c) {
  _contents[row * _width + col] = c;
  return *this;
}
inline Screen &Screen::Display(std::ostream &os) {
  _DoDisplay(os);
  return *this;
}
inline const Screen &Screen::Display(std::ostream &os) const {
  _DoDisplay(os);
  return *this;
}
inline void Screen::_DoDisplay(std::ostream &os) const {
  os << _contents;
}
