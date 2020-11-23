/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 44ms 93.20% 14.2MB 100.00%
// brute force
// O(HW) O(HW)
class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& G, int k) {
    int h = G.size(), w = G[0].size();
    vector<vector<int>> R(h, vector<int>(w, 0));
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        int ny = (y + (x + k) / w) % h;
        int nx = (x + k) % w;
        R[ny][nx] = G[y][x];
      }
    }
    return R;
  }
};
