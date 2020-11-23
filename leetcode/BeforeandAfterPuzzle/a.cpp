/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

// 16ms 71.91% 13.6MB 100.00%
// hash map
// O(N) O(N)
class Solution {
 public:
  std::vector<std::string> beforeAndAfterPuzzles(
      std::vector<std::string>& P) {
    std::unordered_map<std::string, std::set<std::string>>
        ump_first, ump_last;
    std::set<std::string> ans;
    for (auto& s : P) {
      int i = s.find(' '), j = s.rfind(' ');
      i = i == std::string::npos ? s.size() : i;
      j = j == std::string::npos ? 0 : j + 1;
      for (auto ss : ump_first[s.substr(j)])
        ans.insert(s + ss);
      for (auto ss : ump_last[s.substr(0, i)])
        ans.insert(ss + s);
      ump_first[s.substr(0, i)].insert(s.substr(i));
      ump_last[s.substr(j)].insert(s.substr(0, j));
    }
    return std::vector<std::string>(ans.begin(), ans.end());
  }
};

int main() {
  return 0;
}
