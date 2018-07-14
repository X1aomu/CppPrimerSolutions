#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void EliminateDups(vector<string> &words) {
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
}
