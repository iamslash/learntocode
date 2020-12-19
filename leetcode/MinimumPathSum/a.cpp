/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

// 8ms 99.98% 9.9MB 91.07%
// iterative dynamic programming
// O(HW) O(1)
class Solution {
 public:
  int minPathSum(vector<vector<int>>& G) {
    int h = G.size(), w = G[0].size();
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (y > 0 && x > 0) {
          G[y][x] += min(G[y-1][x], G[y][x-1]);
        } else if (y > 0) {
          G[y][x] += G[y-1][x];
        } else if (x > 0) {
          G[y][x] += G[y][x-1];
        }
      }
    }
    return G[h-1][w-1];
  }
};
