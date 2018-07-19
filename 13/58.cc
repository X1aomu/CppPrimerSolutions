#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Foo {
public:
  Foo sorted_56() && {
    cout << "ex13.56 will call the '&&' version" << endl;
    sort(data.begin(), data.end());
    return *this;
  }
  Foo sorted_56() const & {
    cout << "ex13.56 will call the 'const &' version" << endl;
    Foo ret(*this);
    return ret.sorted_56();
  }

  Foo sorted_57() && {
    cout << "ex13.57 will call the '&&' version" << endl;
    sort(data.begin(), data.end());
    return *this;
  }
  Foo sorted_57() const & {
    cout << "ex13.57 will call the 'const &' version" << endl;
    return Foo(*this).sorted_57();
  }

private:
  vector<int> data;
};

int main() {
  Foo foo;
  // foo.sorted_56(); // endless recursive call
  foo.sorted_57();
  return 0;
}
