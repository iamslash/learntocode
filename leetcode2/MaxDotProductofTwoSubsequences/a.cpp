/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// A: 2 1 -2 5
// B: 3 0 -6

// 40ms 58.67% 13.4MB 20.13%
// iterative dynamic programming
// O(NM) O(NM)
class Solution {
 public:
  int maxDotProduct(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> C(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        C[i][j] = A[i] * B[j];
        if (i > 0 && j > 0)
          C[i][j] += max(C[i-1][j-1], 0);
        if (i > 0)
          C[i][j] = max(C[i][j], C[i-1][j]);
        if (j > 0)
          C[i][j] = max(C[i][j], C[i][j-1]);
      }
    }
    return C[n-1][m-1];
  }
};
