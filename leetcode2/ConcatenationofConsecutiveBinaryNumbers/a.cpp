/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <cstdint>

using namespace std;

// n: 3
//    1 10 11
//
//
// n: 12
//    1 10 11 100 101 110 111 1000

// f(0): 0
// f(1): 1        (f(0) << 1) + 1  len(1): 1
// f(2): 110      (f(1) << 2) + 2  len(2): 2
// f(3): 11011    (f(2) << 2) + 3  len(3): 2
// ...
// f(n): (f(n-1) << len(n)) + n

// 68ms 80.91% 6.2MB 93.36%
// math
// O(NlgN) O(1)
#define MOD 1000000007
class Solution {
 public:
  int concatenatedBinary(int n) {
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
      int len = 0;
      for (int j = i; j; ++len) {
        j >>= 1;
      }
      ans = ((ans << len) % MOD + i) % MOD;
    }
    return ans;
  }
};
