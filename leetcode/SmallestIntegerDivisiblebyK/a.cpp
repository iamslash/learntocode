/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// 4ms 75.65% 8.1MB 100.00%
// brute force
// O(K) O(1)
class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    for (int N = 0, cnt = 1; cnt <= K; ++cnt) {
      N = (N * 10 + 1) % K;
      if (N == 0)
        return cnt;
    }
    return -1;
  }
};

int main() {
  return 0;
}
