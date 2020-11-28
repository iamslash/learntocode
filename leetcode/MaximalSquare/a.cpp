/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//[["1","1","1","1","0"],
// ["1","1","1","1","0"],
// ["1","1","1","1","1"],
// ["1","1","1","1","1"],
// ["0","0","1","1","1"]]

// 36ms 84.10% 12.1MB 11.24%
// iterative dynamic programming
// O(HW) O(N)
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& M) {
    int h = M.size(), w = M[0].size(), ans = 0;
    vector<vector<int>> C(h, vector<int>(w));
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (M[y][x] == '0') {
          continue;
        }
        int a = 0, b = 0, c = 0;
        if (y > 0) {
          a = C[y-1][x];
        }
        if (x > 0) {
          b = C[y][x-1];
        }
        if (y > 0 && x > 0) {
          c = C[y-1][x-1];
        }
        C[y][x] = 1 + min(a, min(b, c));
        ans = max(ans, C[y][x]);
      }
    }
    return ans * ans;
  }
};
