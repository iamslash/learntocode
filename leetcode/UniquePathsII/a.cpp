/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 0 0 0
// 0 1 0
// 0 0 0
//
// 1 1 2
// 

// 94.85% 4ms 8MB 100.00%
// dynamic programming
// O(HW) O(W)
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& G) {    
    int h = G.size(), w = G[0].size();
    if (G[0][0] == 1 || G[h-1][w-1] == 1)
      return 0;
    vector<int> C(w, 0);
    C[0] = 1;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 1) {
          C[x] = 0;
        } else if (x > 0) {
          C[x] += C[x-1];
        }
      }
    }
    return C[w-1];
  }
};
