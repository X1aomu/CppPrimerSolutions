#include <iostream>
#include <vector>

void TestIntVector(const std::vector<int> &ivec) {
  std::cout << "\tsize " << ivec.size() << " capacity " << ivec.capacity()
            << std::endl;
}

int main() {
  std::cout << "Test int vector:" << std::endl;
  std::vector<int> ivec;
  std::cout << "Now initializing ..." << std::endl;
  TestIntVector(ivec);
  std::cout << "Now pushing 24 integers ..." << std::endl;
  for (std::vector<int>::size_type ix = 0; ix != 24; ++ix) {
    ivec.push_back(ix);
    TestIntVector(ivec);
  }
  std::cout << "Now reserving its capacity to 50 ..." << std::endl;
  ivec.reserve(50);
  TestIntVector(ivec);
  std::cout << "Now trying to use up its capacity ..." << std::endl;
  while (ivec.size() != ivec.capacity()) {
    ivec.push_back(0);
  }
  TestIntVector(ivec);
  std::cout << "Now pushing one more integer ..." << std::endl;
  ivec.push_back(0);
  TestIntVector(ivec);
  std::cout << "Now reducing its capacity to fit its size ..." << std::endl;
  ivec.shrink_to_fit();
  TestIntVector(ivec);
  std::cout << "Now pushing one more integer again ..." << std::endl;
  ivec.push_back(0);
  TestIntVector(ivec);
  std::cout << "Testing completed." << std::endl;
  return 0;
}
