#include <fstream>
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "ERROR: missing parameter!" << endl;
    return -1;
  }
  std::ifstream input_file(argv[1]);
  if (!input_file) {
    cerr << "ERROR: " << argv[1] << ": file not found" << endl;
    return -1;
  }
  string word, longest_word;
  while (input_file >> word) {
    if (word.find_first_not_of("acemnorsuvwxz") == string::npos) {
      longest_word = word;
    }
  }
  if (longest_word.size()) {
    cout << longest_word << endl;
  } else {
    cout << "No match found!" << endl;
  }
  return 0;
}
