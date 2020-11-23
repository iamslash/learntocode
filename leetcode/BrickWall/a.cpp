/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>
#include <unordered_map>

// 24ms 94.12%
// hash
// O(N) O(N)
class Solution {
 public:
  int leastBricks(std::vector<std::vector<int>>& W) {
    std::unordered_map<int, int> edges;
    int h = W.size();
    int min_bricks = h;
    for (const auto& l : W) {
      for (int i = 0, w = 0; i < l.size() - 1; ++i) {
        w += l[i];
        int cnt_edge = ++edges[w];
        min_bricks = std::min(min_bricks, h - cnt_edge);
      }
    }
    return min_bricks;
  }
};

int main() {
  std::vector<std::vector<int>> W = {
    {1,2,2,1},
    {3,1,2},
    {1,3,2},
    {2,4},
    {3,1,2},
    {1,3,1,1}
  };
  Solution sln;
  printf("%d\n", sln.leastBricks(W));
  
  return 0;
}
