/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// 1 0 1 0 0
// 1 1 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// iterative dynamic programming
// O(HW) O(1)
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& M) {
    if (M.empty() || M[0].empty())
      return 0;
    int h = M.size(), w = M[0].size(), ans = 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        M[y][x] -= '0';
        int a = 0, b = 0, c = 0;
        if (y > 0 && x > 0)
          a = M[y-1][x-1];
        if (y > 0)
          b = M[y-1][x];
        if (x > 0)
          c = M[y][x-1];
        if (M[y][x] > 0)
          M[y][x] = min(a, min(b, c)) + 1;
        ans = max(ans, M[y][x] * M[y][x]);
      }
    }
    return ans;
  }
};
