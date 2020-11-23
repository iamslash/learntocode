/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// n: 10
//    .         .         .
//              s
// C: 1 1 1 2 4 0 0 0 0 0 0 0
//          i

// 0ms 100.00% 6.4MB 11.49%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> C(n+1);
    C[0] = 1, C[1] = 1;
    for (int sum = 2; sum <= n; sum++) {
      for (int i = 1; i < sum; ++i) {
        C[sum] = max(C[sum], max((sum-i)*i, C[sum-i] * i));
      }
    }
    return C[n];
  }
};
