/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 8ms 51.21% 8.2MB 17.34%
// iterative dynamic programming
// O(HW^2) O(HW)
class Solution {
 public:
  int maxStudents(vector<vector<char>>& G) {
    int h = G.size(), w = G[0].size();
    vector<int> validVec;
    for (int y = 0; y < h; ++y) {
      int bm = 0;
      for (int x = 0; x < w; ++x) {
        bm = bm * 2 + (G[y][x] == '.');
      }
      validVec.push_back(bm);
    }
    vector<vector<int>> C(h+1, vector<int>(1 << w, -1));
    C[0][0] = 0;
    for (int y = 1; y <= h; ++y) {
      int bm = validVec[y-1];
      for (int x = 0; x < (1 << w); ++x) {
        if ((x & bm) == x && !(x & (x >> 1))) {
          for (int k = 0; k < (1 << w); ++k) {
            if (!(x & (k >> 1)) && !((x >> 1) & k)
                && C[y-1][k] != -1) {
              C[y][x] = max(C[y][x], C[y-1][k] + __builtin_popcount(x));
            }
          }
        }
      }
    }
    return *max_element(C[h].begin(), C[h].end());
  }
};
