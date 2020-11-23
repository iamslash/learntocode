/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

// 4ms 89.51% 8.2MB 79.23%
// iterative dynamic programming
// O(KN^2) O(N^2)
class Solution {
 public:
  int mergeStones(vector<int>& S, int K) {
    int n = S.size();
    if ((n-1) % (K-1) > 0)
      return -1;
    vector<int> ps(n+1);
    for (int i = 0; i < n; ++i)
      ps[i+1] = ps[i] + S[i];
    vector<vector<int>> C(n, vector<int>(n));
    for (int m = K; m <= n; ++m) {
      for (int i = 0; i + m <= n; ++i) {
        int j = i + m - 1;
        C[i][j] = INT_MAX;
        for (int mi = i; mi < j; mi += K-1) {
          C[i][j] = min(C[i][j], C[i][mi] + C[mi+1][j]);          
        }
        if ((j-i)%(K-1) == 0)
          C[i][j] += ps[j+1] - ps[i];
      }
    }
    return C[0][n-1];
  }
};
