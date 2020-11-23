/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

// 124ms 46.22% 13.8MB 38.70%
//      i
// s: 1 0 0 1
#define MOD 1000000007
class Solution {
 public:
  int numWays(string s) {
    int64_t ans = 0, n = s.size(), cntOne = 0;
    if (n < 3)
      return 0;
    cntOne = count_if(s.begin(), s.end(), [](const char a){return a == '1';});
    if (cntOne % 3 != 0)
      return 0;
    if (cntOne == 0)
      return (int) ((n-1) * (n-2) / 2 % MOD);
    int64_t firstZero = 0, secondZero = 0, avg = cntOne/3, prefixOne = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        prefixOne++;
      } else {
        if (prefixOne == avg) {
          firstZero++;
        } else if (prefixOne == avg * 2) {
          secondZero++;
        }
      }
    }
    return (int)(++firstZero * ++secondZero % MOD);
  }
};
