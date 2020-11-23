/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// C[i][j][k]: minimum value of
//  i: position of the house to color
//  j: count of remained group (target)
//  k: last color of the houses[i]

// 224ms 19.33% 21.2MB 100.00%
// dynamic programming
// O(MMN) O(MMN)
#define MAXVAL 1000001
class Solution {
 private:
  int dfs(vector<int>& houses, vector<vector<int>>& cost,
          int m, int n,
          vector<vector<vector<int>>>& C, int pos, int target, int lastCol) {
    // base
    if (pos >= m || target < 0) {
      if (target == 0)
        return 0;
      return MAXVAL;
    }
    // recursion
    // Painted last year, just skip it.
    if (houses[pos] != 0) {
      return dfs(houses, cost, m, n, C,
                 pos+1, target - (lastCol != houses[pos]), houses[pos]);
    }
    // memo
    int& r = C[pos][target][lastCol];
    if (r >= 0)
      return r;    
    r = MAXVAL;
    // recursion
    for (int col = 1; col <= n; ++col) {
      r = min(r, cost[pos][col-1] +
              dfs(houses, cost, m, n, C,
                  pos+1, target - (lastCol != col), col));
    }          
    return r;
  }
 public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost,
              int m, int n, int target) {
    vector<vector<vector<int>>> C =
           vector<vector<vector<int>>>(
               m+1, vector<vector<int>>(
                   m+1, vector<int>(n+1, -1)));
    int ans = dfs(houses, cost, m, n, C, 0, target, 0);
    if (ans >= MAXVAL)
      return -1;
    return ans;
  }
};
