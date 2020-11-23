// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/816/

#include <cstdio>

class Solution {
 public:
  int trailingZeroes(int n) {
    int r = 0;
    int q;
    while (n > 0) {
      q  = n / 5;
      r += q;
      n  = q;
    }
    return r;
  }
};

int main() {
  // int n = 3;
  // int n = 5;
  int n = 25;
  // int n = 125;

  Solution s;
  printf("%d\n", s.trailingZeroes(n));

  return 0;
}
