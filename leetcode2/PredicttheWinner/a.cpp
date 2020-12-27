/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// 0ms 100.00% 8.1Mb 29.97%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
 private:
  int dfs(vector<vector<int>>& C, vector<int>& P, int i, int j) {
    // base
    if (i > j)
      return 0;
    // memo
    int& r = C[i][j];
    if (r >= 0)
      return r;
    // recursion
    int a = P[i] + min(dfs(C, P, i+2, j), dfs(C, P, i+1, j-1));
    int b = P[j] + min(dfs(C, P, i+1, j-1), dfs(C, P, i, j-2));
    return r = max(a, b);
  }
 public:
  bool PredictTheWinner(vector<int>& P) {
    if (P.size() % 2 == 0)
      return true;
    int n = P.size();
    vector<vector<int>> C(n, vector<int>(n, -1));
    int sum = accumulate(P.begin(), P.end(), 0);
    int score = dfs(C, P, 0, n-1);
    return score * 2 >= sum;
  }
};
