#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {
  size_t n = 10;
  allocator<string> alloc;
  string *const p = alloc.allocate(n);
  auto q = p;

  string s;
  while (cin >> s && q != p + n) {
    *q++ = s;
  }
  const size_t size = q - p;

  for (auto temp = p; temp != q; ++temp) {
    alloc.destroy(temp);
  }
  alloc.deallocate(p, n);

  cout << "Read " << size << " string(s)" << endl;

  return 0;
}
