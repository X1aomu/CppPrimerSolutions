#include <istd::ostream>
#include <string>

// struct Sales_data and function read must be declared here because of loop
// dependancy
inline std::istream &read(std::istream &, Sales_data &);
inline std::ostream &print(std::ostream &, const Sales_data &);

class Sales_data {
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

public:
  // Constructors
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo_(s), units_sold_(n), revenue_(n * p) {}
  Sales_data() = Sales_data("", 0, 0);
  Sales_data(const std::string &s) : Sales_data(s, 0, 0){};
  Sales_data(std::istream &is) : Sales_data("", 0, 0) {
    read(is, *this);
  } // Loop dependancy
  // member functions
  inline std::string isbn() const { return bookNo_; };
  class Sales_data &combine(const Sales_data &);

private:
  std::string bookNo_;
  unsigned units_sold_ = 0;
  double revenue_ = 0.0;

  inline double AvgPrice() const {
    return units_sold_ ? revenue_ / units_sold_ : 0.0;
  }
};

class Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold_ += rhs.units_sold_;
  revenue_ += rhs.revenue_;
  return *this;
}

std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0.0;
  // Input format: ISBN units_sold_ price
  is >> item.bookNo_ >> item.units_sold_ >> price;
  item.revenue_ = price * item.units_sold_;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << ' ' << item.units_sold_ << ' ' << item.revenue_ << ' '
     << item.AvgPrice();
  return os;
}

class Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
