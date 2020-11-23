/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/spiral-matrix-ii/description/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> r(n, std::vector<int>(n));
    
    int y = 0, x = 0, dy = 0, dx = 1;
    int xs = 0, xe = n, ys = 0, ye = n;
    int i = 0;
    while (i++ < n*n &&
           y >= ys && y < ye &&
           x >= xs && x < xe)
    {      
      r[y][x] = i;

      // set dy, dx, xs, xe, ys, ye
      if (dy == 0 && dx == 1 && x == xe-1) {
        dy = 1, dx = 0, ys += 1;
      } else if (dy == 1 && dx == 0 && y == ye-1) {
        dy = 0, dx = -1, xe -= 1;
      } else if (dy == 0 && dx == -1 && x == xs) {
        dy = -1, dx = 0, ye -= 1;
      } else if (dy == -1 && dx == 0 && y == ys) {
        dy = 0, dx = 1, xs += 1;
      }

      y = y + dy;
      x = x + dx;
    }
    return r;    
  }
};

int main() {
  Solution s;

  auto r = s.generateMatrix(3);

  for (auto rr : r) {
    for (int a : rr) {
      printf("%d ", a);
    }
    printf("\n");
  }
  
  return 0;
}
