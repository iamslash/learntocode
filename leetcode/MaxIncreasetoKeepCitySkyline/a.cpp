/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 8ms 90.80% 9.3MB 59.43%
// O(HW) O(max(H,W))
class Solution {
 public:
  int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& G) {
    int h = G.size();
    int w = G[0].size();
    std::vector<int> maxcol(w, 0);
    std::vector<int> maxrow(h, 0);
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        maxcol[x] = std::max(maxcol[x], G[y][x]);
        maxrow[y] = std::max(maxrow[y], G[y][x]);
      }
    }
    int r = 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        r += std::min(maxcol[x], maxrow[y]) - G[y][x];
      }
    }
    return r;
  }
};

int main() {
  return 0;
}
