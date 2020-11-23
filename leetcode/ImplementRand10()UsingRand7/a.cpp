/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand7() {
  return 0;
}

// 92ms 39.38%
class Solution {
 public:
  int rand10() {
    int rslt = 40;

    while (rslt >= 40) {
      // rand7()                           generates 1 to 7
      // rand7() -1                        generates 0 to 6
      // 7 * (rand7() - 1) + (rand7() - 1) generates 0 to 48
      //
      rslt = 7 * (rand7() - 1) + (rand7() - 1);
    }
    // rslt is [0, 39]
    return rslt % 10 + 1;
  }
};

int main() {
  return 0;
}
