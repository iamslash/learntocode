/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 44ms 89.38% 13.5% 87.73%
// brute force
// O(HW) O(W)
class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    int h = grid.size(), w = grid[0].size();
    vector<int> ans(w, -1);
    for (int i = 0; i < w; ++i) {
      bool b = true;
      int x = i;
      for (int y = 0; y < h; ++y) {
        if (x < w - 1 &&
            grid[y][x] == 1 &&
            grid[y][x+1] == 1) {
          x += 1;
        } else if (x > 0 &&
                   grid[y][x-1] == -1 &&
                   grid[y][x] == -1) {
          x -= 1;        
        } else {
          b = false;
          break;
        }        
      }
      if (b) {
        ans[i] = x;
      }
    }
    return ans;
  }
};
