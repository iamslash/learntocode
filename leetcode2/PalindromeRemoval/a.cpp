/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 360ms 41.67% 15.6MB 18.18%
// dynamic programming
// O(N^2) O(N^3)
class Solution {
 public:
  int minimumMoves(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 100));
    // when len is 1 or 2
    for (int i = 0; i < n; ++i) {
      C[i][i] = 1;
      if (i < n-1) {
        if (A[i] == A[i+1]) {
          C[i][i+1] = 1;
        } else {
          C[i][i+1] = 2;
        }
      }      
    }
    // when len is 3 or more
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i <= n-len; ++i) {
        int j = i + len - 1;
        C[i][j] = C[i+1][j-1] + (A[i] == A[j] ? 0 : 2);
        for (int k = i; k < j; ++k)
          C[i][j] = min(C[i][j], C[i][k] + C[k+1][j]);
      }
    }
    return C[0][n-1];
  }
};
