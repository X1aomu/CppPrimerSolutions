#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const vector<string> &words) {
  for (auto word : words) {
    cout << word << " ";
  }
  cout << endl;
}

void EliminateDups(vector<string> &words) {
  print(words);
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  print(words);
  words.erase(end_unique, words.end());
  print(words);
}

int main() {
  vector<string> svec;
  string word;
  while (cin >> word) {
    svec.push_back(word);
  }
  EliminateDups(svec);
  return 0;
}
