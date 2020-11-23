/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cmath>
#include <algorithm>

// 208ms 33.65% 7.1MB 100.00%
// dynamic programming
// O(M^K) O(NMK)
class Solution {  
 private:
  int MOD = 1000000007;
  int C[101][51][51] = {}; // C[m][n][k]
  int dfs(int n, int m, int k, int i, int maxVal) {
    // base
    if (n == i)
      return k == 0;
    if (k < 0)
      return 0;
    int& r = C[maxVal][i][k];
    if (r > 0)
      return r - 1;      

    // recursion
    r = 1;
    for (int j = 1; j <= m; ++j) {
      r += dfs(n, m, k - (maxVal < j),
               i + 1,
               std::max(maxVal, j));
      r %= MOD;
    }
    return r - 1;
  }
    
 public:
  int numOfArrays(int n, int m, int k) {
    return dfs(n, m, k, 0, 0);
  }
};
