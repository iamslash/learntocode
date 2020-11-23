/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>

// 912ms 83.02% 47.1MB 32.31%
// brute force
// O(N^2) O(N)
class Solution {
 public:
  int minAreaRect(std::vector<std::vector<int>>& P) {
    int ans = INT_MAX;
    std::unordered_map<int, std::set<int>> rect;
    for (auto& pt : P)
      rect[pt[0]].insert(pt[1]);
    for (auto i = rect.begin(); i != rect.end(); ++i) {
      for (auto j = std::next(i); j != rect.end(); ++j) {
        if (i->second.size() < 2 || j->second.size() < 2)
          continue;
        std::vector<int> ys;
        std::set_intersection(
            i->second.begin(), i->second.end(),
            j->second.begin(), j->second.end(),
            std::back_inserter(ys));
        for (int k = 1; k < ys.size(); ++k)
          ans = std::min(ans,
                         std::abs(j->first - i->first) *
                         (ys[k] - ys[k-1]));
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};

int main() {
  std::vector<std::vector<int>> P = {
    {3,2},
    {0,0},
    {3,3},
    {3,4},
    {4,4},
    {2,1},
    {4,3},
    {1,0},
    {4,1},
    {0,2}
  };
  Solution sln;
  printf("%d\n", sln.minAreaRect(P));
  
  return 0;
}
