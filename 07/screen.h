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
  std::vector<Screen> screens_;
};

class Screen {
  friend void WindowMgr::Clear(const ScreenIndex &i);
 public:
  using pos = std::string::size_type;
  // constructors
  Screen(pos ht, pos wd, char c)
      : height_(ht), width_(wd), contents_(ht * wd, c) {}
  Screen() : Screen(0, 0, 'a') {}  // 'a' can be replaced by any char
  Screen(pos ht, pos wd) : Screen(ht, wd, ' ') {}
  // member functions
  char Get() const;
  char Get(const pos &ht, const pos &wd) const;
  Screen &Move(const pos &r, const pos &c);
  Screen &Set(const char &c);
  Screen &Set(const pos &row, const pos &col, const char &c);
  Screen &Display(std::ostream &os);
  const Screen &Display(std::ostream &os) const;
 private:
  pos cursor_ = 0;
  pos height_ = 0;
  pos width_ = 0;
  std::string contents_;
  // member functions
  void DoDisplay(std::ostream &os) const;
};

// WindowMgr constructor
WindowMgr::WindowMgr(): screens_{Screen(24, 80, ' ')} {}
// WindowMgr::Clear
void WindowMgr::Clear(const ScreenIndex &i) {
  Screen &s = screens_[i];
  s.contents_ = std::string(s.height_ * s.width_, ' ');
}
// Screen::Get
inline char Screen::Get() const {
  return contents_[cursor_];
}
inline char Screen::Get(const pos &ht, const pos &wd) const {
  return contents_[ht * width_ + wd];
}
// Screen::Move
inline Screen &Screen::Move(const pos &r, const pos &c) {
  cursor_ = r * width_ + c;
  return *this;
}
// Screen::Set
inline Screen &Screen::Set(const char &c) {
  contents_[cursor_] = c;
  return *this;
}
inline Screen &Screen::Set(const pos &row, const pos &col, const char &c) {
  contents_[row * width_ + col] = c;
  return *this;
}
// Screen::Display
inline Screen &Screen::Display(std::ostream &os) {
  DoDisplay(os);
  return *this;
}
inline const Screen &Screen::Display(std::ostream &os) const {
  DoDisplay(os);
  return *this;
}
// Screen::DoDisplay
void Screen::DoDisplay(std::ostream &os) const {
  os << contents_;
}
