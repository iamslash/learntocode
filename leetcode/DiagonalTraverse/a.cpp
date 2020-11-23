/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// O(N) O(1)
// 72ms 100.00%
class Solution {
 public:
  std::vector<int> findDiagonalOrder(
      std::vector<std::vector<int>>& M) {
    
    std::vector<int> rslt;
    if (M.empty() || M[0].empty())
      return rslt;
    int h = M.size();
    int w = M[0].size();
    int dy[2] = {-1, 1};  // delta y
    int dx[2] = {1, -1};  // delta x
    int bdir = 0; // true: up, false: down
    int sy = 0, sx = 0; // start y, x
    while (sy < h && sx < w) {
      int ny = sy;
      int nx = sx;
      // printf("sy: %d, sx: %d\n", sy, sx);
      while (ny >= 0 && ny < h &&
             nx >= 0 && nx < w) {

        // printf("  ny: %d, nx: %d\n", ny, nx);       
        rslt.push_back(M[ny][nx]);
        
        ny += dy[bdir];
        nx += dx[bdir];
      }
      sy = ny - dy[bdir];
      sx = nx - dx[bdir];
      if (bdir == 0) {
        if (sx == w - 1)
          sy += 1;
        else
          sx += 1;
      } else {
        if (sy == h - 1)
          sx += 1;
        else
          sy += 1;        
      }      
      bdir = bdir == 0 ? 1 : 0;
    }

    return rslt;
  }
};

int main() {

  // std::vector<std::vector<int>> M = {
  //   {1, 2, 3},
  //   {4, 5, 6},
  //   {7, 8, 9}    
  // };
  std::vector<std::vector<int>> M = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
  };
  Solution sln;
  auto l = sln.findDiagonalOrder(M);
  for (int a : l)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
