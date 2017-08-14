#include <vector>

class Example {
 public:
  static constexpr double rate_ = 6.5;  // must use constexpr
  static constexpr int vec_size_ = 20;
  // cannot initialize vec by constexpr literal type
  static std::vector<double> vec_;
};
