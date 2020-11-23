/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// dynamic programming
// O(N^2) O(N)
#define MOD 1000000007L
class Solution {
 public:
  int numberOfWays(int n) {
    int g = n/2;
    vector<int64_t> C(g+1);
    C[0] = 1L;
    for (int k = 1; k <= g; ++k) {
      for (int i = 0; i < k; ++i) {
        C[k] = (C[k] + C[i] * C[k-i-1]) % MOD;
      }
    }
    return C[g];
  }
};
