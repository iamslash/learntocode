/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

// 124ms 43.50% 49.6MB 100.00%
// sorting
// O(NlgN) O(N)
class Solution {
 public:
  int longestStrChain(std::vector<std::string>& W) {
    std::sort(W.begin(), W.end(), [](const std::string &a,
                                     const std::string &b) {
                                    return a.size() < b.size();
                                  });
    int glbmax = 0;
    // C[string] = count of lonest string chain 
    std::unordered_map<std::string, int> C;
    for (auto &s : W) {
      int locmax = 0;
      for (int i = 0; i < s.size(); ++i) {
        std::string t = s.substr(0, i) + s.substr(i+1);
        locmax = std::max(locmax, C[t] + 1);
      }
      C[s] = locmax;
      glbmax = std::max(glbmax, locmax);
    }
    return glbmax;
  }
};

int main() {
  return 0;
}
