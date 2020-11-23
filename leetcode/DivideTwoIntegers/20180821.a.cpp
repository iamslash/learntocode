/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/820/

#include <cstdio>
#include <limits>

// Rejected: Time Limit Exceeded
class Solution {
public:
  int divide(int p, int q) {
    int rr = 0;
    bool neg = false;
    if ((p > 0 && q < 0) ||
        (p < 0 && q > 0))
      neg = true;
    if (q < 0)
      q = -q;    
    if (p < 0) {
      if (p == std::numeric_limits<int>::min()) {
        rr = 1;
        p += q;
      }
      p = -p;
    }
    // printf("%d %d\n", p, q);
    while (p >= q) {
      p -= q;
      if (rr < std::numeric_limits<int>::max())
        rr++;
    }
    return neg ? -rr : rr;
  }
};

int main() {
  // int a = 10, b = 3;
  // int a = 7, b = -3;
  int a = -2147483648, b = -1;
  Solution s;
  printf("%d\n", s.divide(a, b));
  
  return 0;
}
