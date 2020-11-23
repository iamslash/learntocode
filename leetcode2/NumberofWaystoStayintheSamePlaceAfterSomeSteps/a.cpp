/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 12ms 91.91% 10.1MB 52.11%
// dynamic programming
// O(S^2) O(S^2)
#define MOD 1000000007
class Solution {
 private:
  int dfs(vector<vector<int>>& C, int len, int step, int i) {
    // base
    if (step == 0 && i == 0)
      return 1;
    if (i < 0 || i >= len || step == 0 || i > step)
      return 0;    
    // memo
    int& r = C[step][i];
    if (r >= 0)
      return r;
    // recursion
    r = ((dfs(C, len, step-1, i-1) % MOD +
          dfs(C, len, step-1, i) % MOD) % MOD +
         dfs(C, len, step-1, i+1) % MOD) % MOD;
    return r;
  }
 public:
  int numWays(int steps, int len) {
    vector<vector<int>> C(
        steps+1, vector<int>(steps/2+1, -1));
    return dfs(C, len, steps, 0);
  }
};
