/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// brute force
// 0ms 100.00% 6.1MB 9.04%
class Solution {
 public:
  int numberOfSteps (int num) {
    int ans = 0;
    while (num > 0) {
      if (num & 1)
        num -= 1;
      else
        num /= 2;
      ans++;
    }
    return ans;
  }
};
