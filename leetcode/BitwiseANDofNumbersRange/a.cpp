/* Copyright (C) 2018 by iamslash */
//https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

#include <cstdio>

// 00110
// 11111
class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    int rslt = 0;
    while (m != n) {
      m >>= 1;
      n >>= 1;
      ++rslt;
      // printf("  %d\n", rslt);
    }
    return n << rslt;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.rangeBitwiseAnd(5, 7));
  printf("%d\n", sln.rangeBitwiseAnd(0, 1));
  return 0;
}
