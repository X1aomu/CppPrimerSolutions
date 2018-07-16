#include <fstream>
#include <iostream>

#include <common/str_blob.h>

using namespace std;

int main() {
  const string input_file("data/20");
  ifstream input(input_file);
  if (!input) {
    cout << "Couldn't find data file "
         << "'" << input_file << "'" << endl;
    return 1;
  }

  string line;
  cpp_primer::StrBlob str_blob;
  while (getline(input, line)) {
    str_blob.push_back(line);
  }

  for (auto p = str_blob.begin(); p != str_blob.end(); p.incr()) {
    cout << p.deref() << endl;
  }
}
