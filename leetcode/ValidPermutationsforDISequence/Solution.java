// Copyright (C) 2019 by iamslash

// 2ms 100.00% 35.8Mb 100.00%
// dynamic programming
// O(N^2) O(N^2)
class Solution {
  public int numPermsDISequence(String s) {
    int n = s.length(), MOD = 1000000007;
    int[][] C = new int[n+1][n+1];
    for (int j = 0; j <= n; ++j)
      C[0][j] = 1;
    for (int i = 0; i < n; ++i) {
      if (s.charAt(i) == 'I') {
        for (int j = 0, k = 0; j < n-i; ++j)
          C[i+1][j] = k = (k + C[i][j]) % MOD;
      } else {
        for (int j = n-i-1, k = 0; j >= 0; --j)
          C[i+1][j] = k = (k + C[i][j+1]) % MOD;
      }
    }
    return C[n][0];
  }
}
