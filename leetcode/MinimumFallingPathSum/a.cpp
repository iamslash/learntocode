/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

void printstep(int step, int y, int x) {
  for (int i = 0; i < step; ++i)
    printf("_");
  printf("%d %d\n", y, x);
}
void printmin(int step, int rslt) {
  for (int i = 0; i < step; ++i)
    printf("_");
  printf(":%d\n", rslt);
}

// failed
// class Solution {
//  private:
//   std::vector<std::vector<int>> m_C;
//   std::vector<std::vector<int>> m_M;
//   int m_h;
//   int m_w;
//   int solve(int y, int x, int v) {
//     printstep(y, y, x);
    
//     // base
//     if (y >= m_h || x < 0 || x >= m_w)
//       return std::numeric_limits<int>::max();

//     // memoization
//     int& r = m_C[y][x];
//     if (r > std::numeric_limits<int>::min())
//       return r;

//     // recursion
//     v += m_M[y][x];
//     r = solve(y+1, x, v);
//     r = std::min(r, solve(y+1, x-1, v));
//     r = std::min(r, solve(y+1, x+1, v));
//     r += v;

//     printmin(y, r);

//     return r;
//   }
//  public:
//   int minFallingPathSum(std::vector<std::vector<int>>& M) {
//     m_h = M.size();
//     m_w = M[0].size();
//     m_M = M;
//     m_C = std::vector<std::vector<int>>(m_h,
//                                         std::vector<int>(m_w, std::numeric_limits<int>::min()));
//     int rslt = std::numeric_limits<int>::max();
//     for (int x = 0; x < m_h; ++x) {
//       rslt = std::min(rslt, solve(0, x, 0));
//     }
//     return rslt;
//   }
// };

// 12ms 43.65%
class Solution {
 public:
  int minFallingPathSum(std::vector<std::vector<int>>& M) {
    int h = M.size();
    int w = M[0].size();
    for (int y = 1; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        M[y][x] += std::min(M[y-1][x],
                            std::min(M[y-1][std::max(0, x-1)],
                                     M[y-1][std::min(w-1, x+1)]));                                     
      }
    }
    std::vector<int>& MM = M.back();
            
    return *std::min_element(MM.begin(), MM.end());
  }
};

int main() {
  std::vector<std::vector<int>> M = {{1,2,3},{4,5,6},{7,8,9}};

  Solution sln;
  printf("%d\n", sln.minFallingPathSum(M));
  
  return 0;
}
