/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 132ms 86.95% 24.1MB 21.42%
// iterative dynamic programming\
// O(HW) O(1)
class Solution {
 public:
  int countSquares(vector<vector<int>>& M) {
    int h = M.size(), w = M[0].size(), cnt = 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (M[y][x] > 0 && y > 0 && x > 0) {
          int minLen = min(M[y][x-1], min(M[y-1][x-1], M[y-1][x]));
          M[y][x] = minLen + 1;
        }
        cnt += M[y][x];
      }
    }
    return cnt;
  }
};
