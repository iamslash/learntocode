/* Copyright (C) 2020 by iamslash */

#include <cstdio>

//        i
//   n: 1 2 3
//        j
// sum: 3
// ans: 5

// 0ms 100.00% 6.5MB 30.00%
// iterative dynamic programming
// O(N^2) O(1)
class Solution {
 public:
  int countVowelStrings(int n) {
    int ans = 0;
    for (int i = 1; i <= n+1; ++i) {
      int sum = 0;
      for (int j = 1; j <= i; ++j) {
        sum += j;
        ans += sum;
      }
    }
    return ans;
  }
};
