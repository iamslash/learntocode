/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 0ms 100.00% 6.8MB 29.29%
// iterative dynamic programming
// O(HW) O(HW)
class Solution {
 public:
  int uniquePaths(int h, int w) {
    vector<vector<int>> C(h, vector<int>(w));
    C[0][0] = 1;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (y > 0) {
          C[y][x] += C[y-1][x];
        }
        if (x > 0) {
          C[y][x] += C[y][x-1];
        }
      }
    }
    return C[h-1][w-1];
  }
};
