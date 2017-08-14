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
      : _bookNo(s), _units_sold(n), _revenue(n * p) {}
  Sales_data() = Sales_data("", 0, 0);
  Sales_data(const std::string &s) : Sales_data(s, 0, 0){};
  Sales_data(std::istream &is) : Sales_data("", 0, 0) {
    read(is, *this);
  } // Loop dependancy
  // member functions
  inline std::string isbn() const { return _bookNo; };
  class Sales_data &combine(const Sales_data &);

 private:
  std::string _bookNo;
  unsigned _units_sold = 0;
  double _revenue = 0.0;

  inline double avg_price() const {
    return _units_sold ? _revenue / _units_sold : 0.0;
  }
};

class Sales_data &Sales_data::combine(const Sales_data &rhs) {
  _units_sold += rhs._units_sold;
  _revenue += rhs._revenue;
  return *this;
}

std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0.0;
  // Input format: ISBN _units_sold price
  is >> item._bookNo >> item._units_sold >> price;
  item._revenue = price * item._units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << ' ' << item._units_sold << ' ' << item._revenue << ' '
     << item.avg_price();
  return os;
}

class Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
