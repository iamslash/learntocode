/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 80ms 58.71% 10.4MB 47.07%
// dynamic programming
// O(N^2) O(N^2)
#define MAXVAL 1000000007
class Solution {
 private:
  int dfs(vector<vector<int>>& C, vector<int>& A, int i, int j) {
    // base
    if (j - i <= 1)
      return 0;
    // memo
    int& r = C[i][j];
    if (r >= 0)
      return r;
    // recursion
    r = MAXVAL;
    for (int k = i+1; k < j; ++k) {
      r = min(r, A[j]-A[i] +
              dfs(C, A, i, k) +
              dfs(C, A, k, j));
    }
    return r;
  }
 public:
  int minCost(int n, vector<int>& A) {
    A.push_back(0);
    A.push_back(n);
    sort(begin(A), end(A));
    vector<vector<int>> C(A.size(), vector<int>(A.size(), -1));
    return dfs(C, A, 0, A.size()-1);
  }
};
