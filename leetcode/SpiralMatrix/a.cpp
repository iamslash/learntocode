// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/828/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& vv) {
    std::vector<int> r;
    if (vv.empty() || vv[0].empty())
      return r;
    //
    int y = 0, x = 0, dy = 0, dx = 1;
    int xs = 0, xe = vv[0].size(), ys = 0, ye = vv.size();
    while (y >= ys && y < ye &&
           x >= xs && x < xe) {
      
      r.push_back(vv[y][x]);

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
  std::vector<std::vector<int>> vv = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    };
  // 1,2,3,4,8,12,11,10,9,5,6,7
  Solution s;
  std::vector<int>r = s.spiralOrder(vv);
  for (int a : r) {
    printf("%d ", a);
  }
  printf("\n");
  
  return 0;
}
