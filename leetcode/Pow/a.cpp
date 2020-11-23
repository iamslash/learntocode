/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/818/

#include <cstdio>
#include <limits>
#include <bitset>
#include <iostream>

// 0111
class Solution {
 public:
  double myPow(double x, int n) {
    double rr = 1.0;
    bool negative = n >= 0 ? false : true;
    if (negative) {
      // int min can not be converted positive number
      // so should be added by 1
      if (n == std::numeric_limits<int>::min()) {
        rr = x;
        n++;
      }
      n *= -1;
    }
    while (n > 0) {
      if (n & 1)
        rr *= x;
      n >>= 1;
      x *= x;
    }
    if (negative)
      rr = 1.0 / rr;
    return rr;
  } 
};

int main() {
  Solution s;
  printf("%lf\n", s.myPow(2.10000, 3));
  printf("%lf\n", s.myPow(2.00000, -2));
  printf("%lf\n", s.myPow(2.00000, -2147483648));
  return 0;
}
