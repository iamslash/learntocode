/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 92ms 53.54% 28.4MB 54.84%
// O(HW) O(HW)
class Solution {
 public:
  int longestLine(std::vector<std::vector<int>>& M) {
    int maxr = 0;
    if (M.empty() || M[0].empty())
      return maxr;
    int h = M.size();
    int w = M[0].size();
    std::vector<std::vector<std::vector<int>>> C(
        4, std::vector<std::vector<int>>(
            h, std::vector<int>(w, 0)));
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        // compare row
        if (y > 0)
          C[0][y][x] = M[y-1][x] ? C[0][y-1][x] + M[y][x] : M[y][x];
        else 
          C[0][y][x] = M[y][x];
        maxr = std::max(maxr, C[0][y][x]);
        
        // compare col
        if (x > 0)
          C[1][y][x] = M[y][x-1] ? C[1][y][x-1] + M[y][x] : M[y][x];
        else
          C[1][y][x] = M[y][x];
        maxr = std::max(maxr, C[1][y][x]);
            
        // compare dia
        if (y > 0 && x < w - 1)          
          C[2][y][x] = M[y-1][x+1] ? C[2][y-1][x+1] + M[y][x] : M[y][x];            
        else
          C[2][y][x] = M[y][x];
        maxr = std::max(maxr, C[2][y][x]);
            
        // compare ant
        if (y > 0 && x > 0)
          C[3][y][x] = M[y-1][x-1] ? C[3][y-1][x-1] + M[y][x] : M[y][x];
        else 
          C[3][y][x] = M[y][x];
        maxr = std::max(maxr, C[3][y][x]);
        // printf("%d (%d,%d) %d %d %d %d (%d)\n", M[y][x], y, x,
        //        C[0][y][x], C[1][y][x], C[2][y][x], C[3][y][x], maxr);
      }
    }
    return maxr;
  }
};

int main() {

  std::vector<std::vector<int>> M = {
    {1,1,0,1},
    {1,0,1,0},
    {1,1,0,1}
  };
  Solution sln;
  printf("%d\n", sln.longestLine(M));
  
  return 0;
}
