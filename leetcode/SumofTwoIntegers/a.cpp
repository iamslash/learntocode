/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/114/others/822/

#include <cstdio>

class Solution {
 public:
  int getSum(int a, int b) {
    int c = 0;
    int r = 0;
    for (int i = 0; i < 32; ++i) {
      // c: 0 a: 0 b: 0   r: 0 c: 0
      // c: 0 a: 1 b: 0   r: 1 c: 0
      // c: 0 a: 0 b: 1   r: 1 c: 0
      // c: 0 a: 1 b: 1   r: 0 c: 1
      // c: 1 a: 0 b: 0   r: 1 c: 0
      // c: 1 a: 1 b: 0   r: 0 c: 1
      // c: 1 a: 0 b: 1   r: 0 c: 1
      // c: 1 a: 1 b: 1   r: 1 c: 1
      // printf("c: %d, a: %d, b: %d\n", c, a, b);
      if (c == 0) {
        if (!(a&1) && !(b&1)) {
          r &= ~(1<<i);
          c = 0;
        } else if (((a&1) && !(b&1)) ||
                   (!(a&1) && (b&1))) {
          r |= (1<<i);
          c = 0;
        } else {
          r &= ~(1<<i);          
          c = 1;
        }
      } else {
        if (!(a&1) && !(b&1)) {
          r |= (1<<i);
          c = 0;
        } else if (((a&1) && !(b&1)) ||
                   (!(a&1) && (b&1))) {
          r &= ~(1<<i);          
          c = 1;
        } else {
          r |= (1<<i);
          c = 1;
        }
      }
      a >>= 1;
      b >>= 1;
    }
    return r;    
  }
};

int main() {
  int a = 10, b = 2;
  Solution s;
  printf("%d\n", s.getSum(a, b));
  return 0;
}
