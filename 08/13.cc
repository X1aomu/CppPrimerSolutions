#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

struct PersonInfo {
  string name;
  vector<string> phones;
};

int main() {
  const string input_file("data/13");
  ifstream input(input_file);
  if (input) {
    string line, word;
    istringstream record;
    vector<PersonInfo> people;
    while (getline(input, line)) {
      PersonInfo info;
      record.clear();
      record.str(line);
      record >> info.name;
      while (record >> word) {
        info.phones.push_back(word);
      }
      people.push_back(info);
    }
    // testing
    for (const auto &entry : people) {
      cout << entry.name << ": ";
      for (const auto &num : entry.phones) {
        cout << num << ' ';
      }
      cout << endl;
    }
  } else {
    cerr << input_file << ": file not found!" << endl;
  }
}
