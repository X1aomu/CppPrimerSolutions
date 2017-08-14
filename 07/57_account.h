#include <string>

class Account {
 public:
  void Calculate() { amount_ += amount_ * interest_rate_ }
  static double Rate() { return interest_rate_; }
  static void Rate(double new_rate);
 private:
  std::string owner_;
  double amount_;
  static double interest_rate_;
  static double InitRate();
}

void Account::Rate(double new_rate) {
  interest_rate_ = new_rate;
}
double Account::InitRate() {
  return 0.0035;
}
double Account::interest_rate_ = InitRate();
