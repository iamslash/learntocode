/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// stones: 5 3 1 4 2    5 3 1 4
//    sum: 15           13
//  alice: 0            13
//    bob: 0            0
//
// stones: 3 1 4        1 4
//    sum: 8            5
//  alice: 13           18
//    bob: 8            8
//
// stones: 4
//    sum: 4
//  alice: 18           
//    bob: 12           

// 332ms 58.75% 379.5MB 5.21%
// recursive dynamic programming, top down programming
// O(N^2) O(N^2)
class Solution {
 private:
  int dfs(vector<vector<int>>& C, vector<int>& stones,
          int i, int j, int sum) {
    // base
    if (i == j)
      return 0;
    // memeo
    int& r = C[i][j];
    if (r >= 0)
      return r;
    // recursion
    r = max(sum - stones[i] -
            dfs(C, stones, i+1, j, sum - stones[i]),
            sum - stones[j] -
            dfs(C, stones, i, j-1, sum - stones[j]));
    return r;
  };
 public:
  int stoneGameVII(vector<int>& stones) {
    vector<vector<int>> C(1001, vector<int>(1001, -1));
    int n = stones.size();
    int sum = accumulate(stones.begin(), stones.end(), 0);
    return dfs(C, stones, 0, n-1, sum); 
  }
};
