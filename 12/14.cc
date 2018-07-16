#include <iostream>
#include <memory>

using namespace std;

struct Destination {};

struct Connection {};

Connection Connect(Destination *d_ptr) {
  Connection c;
  return c;
}

void Disconnect(Connection c) {}

void EndConnection(Connection *p) { Disconnect(*p); }

void func(Destination &d) {
  Connection c = Connect(&d);
  shared_ptr<Connection> p(&c, EndConnection);
}

int main() {
  Destination d;
  func(d);
  return 0;
}
