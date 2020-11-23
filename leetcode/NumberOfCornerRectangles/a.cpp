/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 384ms 66.67% 24.6MB 76.73%
// math, combination
// O(H^2W) O(1)
class Solution {
 public:
  int countCornerRectangles(vector<vector<int>>& G) {
    int ans = 0, h = G.size(), w = G[0].size();
    for (int y = 0; y < h-1; ++y) {
      for (int i = y+1; i < h; ++i) {
        int cnt = 0;
        for (int x = 0; x < w; ++x) {
          if (G[y][x] && G[i][x])
            cnt++;
        }
        ans += cnt * (cnt-1) / 2;
      }
    }
    return ans;
  }
};
