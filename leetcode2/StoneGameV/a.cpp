/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// 728ms 27.15% 22.3MB 44.05%
// recursive dynamic programming, partial sum
// O(N^2) O(N^2)
class Solution {
 private:
  vector<int> PS;
  vector<vector<int>> C;
  void printv(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i)
      printf("%d ", A[i]);
    printf("\n");
  }
  int dfs(vector<int>& S, int i, int j) {
    // base
    if (i == j)
      return 0;    
    // memo
    int& r = C[i][j];
    if (r >= 0)
      return r;
    // recursion
    r = 0;
    for (int k = i+1; k <= j; k++) {
      int left = PS[k] - PS[i], right = PS[j+1] - PS[k];
      if (left < right) {
        r = max(r, left + dfs(S, i, k-1));
      } else if (left > right) {
        r = max(r, right + dfs(S, k, j));
      } else {
        r = max(r, left + max(dfs(S, k, j), dfs(S, i, k-1)));
      }
    }
    return r;
  }
 public:
  int stoneGameV(vector<int>& S) {
    int n = S.size();
    PS = vector<int>(n+1);
    C = vector<vector<int>> (n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i)
      PS[i+1] = PS[i] + S[i];
    // printv(PS);
    return dfs(S, 0, n-1);
  }
};
