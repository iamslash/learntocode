/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cstdint>

// 0ms 100.00% 6.1MB 100.00%
// dynamic programming
// O(N) O(1)
class Solution {
 public:
  int numOfWays(int n) {
    int mod = 1000000007;
    int64_t a121 = 6, a123 = 6;
    int64_t b121 = 0, b123 = 0;
    for (int i = 1; i < n; ++i) {
      b121 = a121 * 3 + a123 * 2;
      b123 = a121 * 2 + a123 * 2;
      a121 = b121 % mod;
      a123 = b123 % mod;
    }
    return (int)((a121 + a123) % mod);
  }
};
