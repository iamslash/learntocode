/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

// 220ms 56.04% 9.4MB 50.57%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int numSquares(int n) {
    vector<int> C(n+1, INT_MAX);
    C[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j*j < i; ++j) {
        C[i] = min(C[i], C[i-j*j] + 1);
      }
    }
    return C[n];
  }
};
