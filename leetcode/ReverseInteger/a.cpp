// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/880/

#include <cstdio>
#include <climits>

class Solution {
 public:
  int reverse(int x) {
    int64_t r = 0;
    do {
      r = r*10 + x%10;
      x /= 10;
    } while (x);
    return INT_MIN <= r && r <= INT_MAX ? r : 0;
  }
};

// 123
// r:   3, x: 12
// r:  32, x:  1
// r: 321, x:  0
int main() {
  Solution s;
  printf("%d\n", s.reverse(123));
  return 0;
}
