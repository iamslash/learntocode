/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 176ms 73.51% 15MB 84.21%
// dfs with memoization
// O(N^2*K) O(N*K)
class Solution {
 private:
  int dfs(std::vector<std::vector<int>>& F,
          std::vector<std::vector<int>>& D,
          int src, int week,
          std::vector<std::vector<int>>& C) {
    int ncity = D.size();
    int nweek = D[0].size();
    // base
    if (week == nweek)
      return 0;
    
    // memoization
    int& r = C[src][week];
    if (r != -1)
      return r;
    r = 0;
    
    // recursion
    int maxdays = 0;
    for (int dst = 0; dst < ncity; ++dst) {
      if (F[src][dst] == 1 || dst == src) {
        maxdays = std::max(maxdays, D[dst][week] + dfs(F, D, dst, week+1, C));
      }
    }
    
    return r = maxdays;
  }
 public:
  int maxVacationDays(
      std::vector<std::vector<int>>& F,
      std::vector<std::vector<int>>& D) {
    int ncity = D.size();
    int nweek = D[0].size();
    std::vector<std::vector<int>> C(ncity, std::vector<int>(nweek, -1));
    return dfs(F, D, 0, 0, C);
  }
};

int main() {

  // y: city, x: city
  std::vector<std::vector<int>> F = {
    {0,1,1},
    {1,0,1},
    {1,1,0}
  };
  // y: city, x: week
  std::vector<std::vector<int>> D = {
    {1,3,1},
    {6,0,3},
    {3,3,3}
  };
  // 6 + 3 + 3
  Solution sln;
  printf("%d\n", sln.maxVacationDays(F, D));
  
  return 0;
}
