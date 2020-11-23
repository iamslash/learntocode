/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

// 4ms 52.29% 8.1MB 94.44%
// binary search
// O(lgN) O(1)
int guess(int num);
class Solution {
 public:
  int guessNumber(int n) {
    int l = 0, m = 0, h = n;
    while (l < h) {
      m = l + (h - l) / 2;
      if (guess(m) > 0) {
        l = m + 1;
      } else {
        h = m;
      }
    }
    return l;
  }
};

int main() {
  return 0;
}
