#include <iostream>
#include <string>
#include <vector>

class Screen;

class WindowMgr {
 public:
  // constructors
  WindowMgr();
  // Index for each screen in a window
  using ScreenIndex = std::vector<Screen>::size_type;
  //typedef std::vector<Screen>::size_type ScreenIndex;
  void Clear(const ScreenIndex &i);  // clear a screen
 private:
  std::vector<Screen> _screens;
};

class Screen {
  friend void WindowMgr::Clear(const ScreenIndex &i);
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
  // member functions
  void _DoDisplay(std::ostream &os) const;
};

// WindowMgr constructor
WindowMgr::WindowMgr(): _screens{Screen(24, 80, ' ')} {}
// WindowMgr::Clear
void WindowMgr::Clear(const ScreenIndex &i) {
  Screen &s = _screens[i];
  s._contents = std::string(s._height * s._width, ' ');
}
// Screen::Get
inline char Screen::Get() const {
  return _contents[_cursor];
}
inline char Screen::Get(const pos &ht, const pos &wd) const {
  return _contents[ht * _width + wd];
}
// Screen::Move
inline Screen &Screen::Move(const pos &r, const pos &c) {
  _cursor = r * _width + c;
  return *this;
}
// Screen::Set
inline Screen &Screen::Set(const char &c) {
  _contents[_cursor] = c;
  return *this;
}
inline Screen &Screen::Set(const pos &row, const pos &col, const char &c) {
  _contents[row * _width + col] = c;
  return *this;
}
// Screen::Display
inline Screen &Screen::Display(std::ostream &os) {
  _DoDisplay(os);
  return *this;
}
inline const Screen &Screen::Display(std::ostream &os) const {
  _DoDisplay(os);
  return *this;
}
// Screen::_DoDisplay
void Screen::_DoDisplay(std::ostream &os) const {
  os << _contents;
}
