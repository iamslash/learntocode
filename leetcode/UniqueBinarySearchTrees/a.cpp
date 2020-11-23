/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// T[0] = 0
// T[1] = 1
// T[2] = T[0] * T[1] + T[1] * T[0]
// T[3] = T[0] * T[2] +
//        T[1] * T[1] +
//        T[2] * T[0]

// T[n] = T[0]   * T[n-1] +
//        T[1]   * T[n-2] +
//        ...
//        T[n]   * T[1] +
//        T[n-1] * T[0]

// iterative dynamic programming
// O(N^2) O(N)
// 0ms 100.00% 6.2MB 100.00%
class Solution {
 public:
  int numTrees(int n) {
    vector<int> C(n+1);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        C[i] += C[j-1] * C[i-j];
      }
    }
    return C[n];
  }
};
