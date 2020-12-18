/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;

// 112ms 100.00% 6.8MB 100.00%
// iterative dynamic programming
// O(K) O(K)
#define MOD 1000000007
class Solution {
 public:
  int waysToDistribute(int n, int k) {
    vector<int64_t> C(k+1, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = min(i, k); j > 1; j--) {
        C[j] = (j * C[j] + C[j-1]) % MOD;
      }
    }
    return C[k];
  }
};


