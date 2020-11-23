/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

// 48ms 90.82% 11.8MB 95.70%
// binary search
// O(N^2lgN) O(1)
class Solution {
 private:
  // return days for bound bnd
  int countDays(std::vector<int>& W, int bnd) {
    int days = 1, cur = 0;
    for (int w : W) {
      cur += w;
      if (cur > bnd) {
        ++days;
        cur = w;
      }
    }
    return days;
  }
 public:
  int shipWithinDays(std::vector<int>& W, int D) {
    int hi = 500*50000;
    int lo = *std::max_element(W.begin(), W.end());
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (countDays(W, mi) <= D)
        hi = mi;
      else
        lo = mi + 1;
    }
    return lo;
  }
};

int main() {
  return 0;
}
