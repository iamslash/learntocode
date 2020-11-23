/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/819/

#include <cstdio>
#include <algorithm>

class Solution {
 public:
  // binary search
  int mySqrt(int x) {
    if (x <= 1)
      return x;
    // 46340 = floor(sqrt(INT_MAX))
    int l = 1, m, h = std::min(46340, x), rr;
    while (l <= h) {
      m = (l + h) / 2;

      if (m * m == x) {
        return m;
      } else if (m * m < x) {
        l = m + 1;
        rr = m;
      } else {
        h = m - 1;
      }
    }
    return rr;
  }
};

int main() {
  int n = 2147395599;
  
  Solution s;
  printf("%d\n", s.mySqrt(n));
    
  return 0;
}
