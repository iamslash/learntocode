/* Copyright (C) 2020 by iamslash */

// https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/discuss/117821/Four-binary-search-solutions-based-on-different-ideas

#include <cstdio>
#include <cstdint>
#include <cstdlib>

using namespace std;

// 1 2 3 4 5 6 7 8 9 10 11

// 0ms 100.00% 5.9MB 91.09%
// binary search
// O((logK)^2) O(1)
class Solution {
 private:
  int64_t numOfTrailingZeros(int64_t x) {
    int64_t ans = 0;
    while (x > 0) {
      ans += x / 5;
      x /= 5;
    }
    return ans;
  }
  int64_t binarySearch(int K) {
    int64_t lo = 0, hi = 5L * (K+1);
    while (lo <= hi) {
      int64_t mi = lo + (hi - lo) / 2;
      int64_t cnt = numOfTrailingZeros(mi);
      if (cnt <= K) {
        lo = mi + 1;
      } else {
        hi = mi - 1;
      }
    }
    return hi;
  }
 public:
  int preimageSizeFZF(int K) {
    return (int)(binarySearch(K) - binarySearch(K-1));
  }
};

