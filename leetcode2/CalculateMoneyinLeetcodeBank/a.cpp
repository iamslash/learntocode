/* Copyright (C) 2021 by iamslash */

#include <cstdio>

// 1 2 3 4 5 6  7 : 28
// 2 3 4 5 6 7  8 : 28 + 7
// 3 4 5 6 7 8  9 : 28 + 7 + 7
// 4 5 6 7 8 9 10 : 28 + 7 + 7 + 7

//  n : 20
// quo:  2
// rem:  6

// 0ms 100.00% 6.2MB 60.00%
// math
// O(1) O(1)
class Solution {
 public:
  int totalMoney(int n) {
    int quo = n / 7;
    int rem = n % 7;
    int ans = 0;
    if (quo > 0) {
      ans = (28 * quo) + 7 * (quo * (quo-1)) / 2;
    }
    for (int i = 0; i < rem; ++i) {
      ans += quo + i + 1;
    }
    return ans;
  }
};
