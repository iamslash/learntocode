/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// 4ms 95.77% 7.7MB 5.67%
// recursive dynamic programming
// O(N^3) O(N^2)
class Solution {
 private:
  int dfs(vector<int>& P, vector<vector<int>>& C, 
          int i, int M, int left) {
    int n = P.size();
    // memo
    int& r = C[i][M];
    if (r >= 0)
      return r;
    // recursion
    r = 0;
    int taken = 0;
    int bound = min(n, i + 2 * M);
    for (int j = i; j < bound; ++j) {
      taken += P[j];
      int nM = max(M, j - i + 1);
      r = max(r, left - dfs(P, C, j + 1, nM, left - taken));
    }
    return r;
  }
 public:
  int stoneGameII(vector<int>& P) {
    int n = P.size();
    vector<vector<int>> C(n+1, vector<int>(n+1, -1));
    int sum = accumulate(P.begin(), P.end(), 0);
    return dfs(P, C, 0, 1, sum);    
  }
};
