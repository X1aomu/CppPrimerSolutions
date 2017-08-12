#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  std::string isbn() const { return bookNo; };
  double avg_price() const { return units_sold ? revenue / units_sold : 0.0; }
  Sales_data &combine(const Sales_data &);
};
istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);

int main() {
  return 0;
}

Sales_data & Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
istream &read(istream &is, Sales_data &item) {
  double price = 0.0;
  // Input format: ISBN units_sold price
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}
ostream &print(ostream &os, const Sales_data &item) {
  os << item.isbn() << ' ' << item.units_sold << ' '
     << item.revenue << ' ' << item.avg_price();
  return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
