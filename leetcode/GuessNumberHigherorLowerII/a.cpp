/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 224ms 35.86% 8.6MB 20.95%
// recursive dynamic programming
// O(N^2lgN) O(N^2)
#define MAXVAL 40000
class Solution {
 private:
  int dfs(vector<vector<int>>& C, int s, int e) {
    // base
    if (s >= e)
      return 0;
    // memo
    int& r = C[s][e];
    if (r >= 0)
      return r;
    // recursion
    r = MAXVAL;
    for (int x = s; x <= e; ++x) {
      int t = x + max(dfs(C, s, x-1), dfs(C, x+1, e));
      r = min(r, t);
    }
    return r;
  }
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>>C(n+1, vector<int>(n+1, -1));
    return dfs(C, 1, n);
  }
};
