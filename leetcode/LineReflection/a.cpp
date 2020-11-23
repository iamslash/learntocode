/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <limits>
#include <string>

// 40ms 37.58% 13.2MB 81.25%
// O(N) O(N)
class Solution {
 public:
  bool isReflected(std::vector<std::pair<int, int>>& P) {
    int xmax = std::numeric_limits<int>::min();
    int xmin = std::numeric_limits<int>::max();
    std::unordered_set<std::string> ust;
    for (auto& pr : P) {
      xmax = std::max(xmax, pr.first);
      xmin = std::min(xmin, pr.first);
      ust.insert(std::to_string(pr.first) + "." + std::to_string(pr.second));
    }
    int xsum = xmax + xmin;
    for (auto& pr : P) {
      std::string s = std::to_string(xsum - pr.first) + "." +
          std::to_string(pr.second);
      if (ust.count(s) == 0)
        return false;
    }
    return true;
  }
};

int main() {
  return 0;
}
