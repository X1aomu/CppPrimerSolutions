#include <fstream>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

// struct Sales_data and function read must be declared here because of loop
// dependancy
struct Sales_data;
istream &read(istream &, Sales_data &);

struct Sales_data {
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data() = default;
  Sales_data(const string &s) : bookNo(s){};
  Sales_data(const string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(n * p) {}
  Sales_data(istream &is) { read(is, *this); } // Loop dependancy

  std::string isbn() const { return bookNo; };
  double avg_price() const { return units_sold ? revenue / units_sold : 0.0; }
  Sales_data &combine(const Sales_data &);
};
ostream &print(ostream &, const Sales_data &);

int main(int argc, char *argv[]) {
  std::ifstream input;
  std::ofstream output;
  if (argc > 2) {
    input.open(argv[1]);
    output.open(argv[2], std::ofstream::app);
  } else {
    cerr << "Loss parameter!" << endl;
    return -1;
  }
  if (input) {
    Sales_data total(input);
    if (!total.bookNo.empty()) {
      Sales_data trans;
      while (read(input, trans)) {
        if (total.isbn() == trans.isbn()) {
          total.combine(trans);
        } else {
          print(output, total) << endl;
          total = trans;
        }
      }
      print(output, total) << endl;
    } else {
      cerr << "No data?!" << endl;
    }
  } else {
    cerr << argv[1] << ": file not found!" << endl;
    return -1;
  }
  return 0;
}

Sales_data &Sales_data::combine(const Sales_data &rhs) {
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
  os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' '
     << item.avg_price();
  return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
