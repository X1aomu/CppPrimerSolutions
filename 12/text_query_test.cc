#include "common/text_query.h"

#include <iostream>

using namespace std;

using cps::TextQuery;

void RunQueries(ifstream &infile) {
  TextQuery tq((infile));
  while (true) {
    cout << "Enter word to look for, or 'q' to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    tq.Query(s).Print(cout);
  }
}

int main(int argc, char **argv) {
  // open the file from which user will query words
  ifstream infile;
  // open returns void, so we use the comma operator XREF(commaOp)
  // to check the state of infile after the open
  if (argc < 2 || !(infile.open(argv[1]), infile)) {
    cerr << "No input file!" << endl;
    return EXIT_FAILURE;
  }
  RunQueries(infile);
  return 0;
}
