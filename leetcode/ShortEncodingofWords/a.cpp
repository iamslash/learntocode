/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>

// 44ms 97.47% 15.8MB 66.29%
// O(NW) O(N)
class Solution {
 public:
  int minimumLengthEncoding(std::vector<std::string>& W) {
    std::unordered_set<std::string> ust(W.begin(), W.end());
    for (auto& w : W) {
      for (int i = 1; i < w.size(); ++i) {
        ust.erase(w.substr(i));
      }
    }
    int rslt = 0;
    for (auto& s : ust)
      rslt += s.size() + 1;
    return rslt;
  }
};

int main() {

  std::vector<std::string> W = {"time", "me", "bell"};

  Solution sln;
  printf("%d\n", sln.minimumLengthEncoding(W));
  
  return 0;
}
