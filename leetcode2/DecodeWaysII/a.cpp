/* Copyright (C) 2020 by iamslash */

#include <cstdio>

//         i
//    s: 1 *
// cnt2: 0
// cnt1: 1
//  cnt: 1 10

// 0ms 100.00% 6.1MB 81.51%
// dynamic programming
// O(N) O(1)
#define MOD 1000000007
class Solution {
 public:
  int numDecodings(string s) {
    // cnt0: number of decodings up two digits before i-th char
    // cnt1: number of decodings up one digit before i-th char
    int cnt0 = 0, cnt1 = 1, n = s.size();
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      char cur = s[i];
      // Consider one digit with cur
      if (cur >= '1') {
        cnt += cnt1 % MOD;
      } else if (cur == '*') {
        cnt += (9 * cnt1) % MOD;
      }
      // Consider two digits with cur
      if (i > 0) {
        char prv = s[i-1];
        if (cur == '*') {
          if (prv == '1') {
            cnt += (cnt0 * 9) % MOD;
          } else if (prv == '2') {
            cnt += (cnt0 * 6) % MOD;
          } else if (prv == '*') {
            cnt += (cnt0 * 15) % MOD;
          }
        }
        if ((cur >= '0' && cur <= '9') && (prv == '1' || prv == '*')) {
          cnt += cnt0;
        }
        if ((cur >= '0' && cur <= '6') && (prv == '2' || prv == '*')) {
          cnt += cnt0;
        }
      }
      cnt0 = cnt1;
      cnt1 = cnt;
    }
    return cnt1;
  }
};
