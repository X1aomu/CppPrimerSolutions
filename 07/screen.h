#include <iostream>
#include <string>

class Screen {
 public:
  using pos = std::string::size_type;
  // constructors
  Screen() = default;
  Screen(pos ht, pos wd) : _heigth(ht), _width(wd) _contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : _heigth(ht), _width(wd) _contents(ht * wd, c) {}
  // member functions
  inline char Get() const { return _contents[_cursor]; }
  char Screen::Get(const pos &ht, const pos &wd) const;
  char Get(const pos &ht, const pos &wd) const;
  class Screen &Move(const pos &r, const pos &c);

 private:
  pos _cursor = 0;
  pos _height = 0;
  pos _width = 0;
  std::string _contents;
}

inline char Screen::Get(const pos &ht, const pos &wd) const {
  return _contents[ht * _width + wd];
}

inline class Screen &Screen::Move(const pos &r, const pos &c) {
  _cursor = r * _width + c;
  return *this;
}
