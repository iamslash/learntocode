/* Copyright (C) 2020 by iamslash */

#include <cstdio>

using namespace std;

// 8ms 63.73% 7.1MB 46.75%
// binary search
// O(lgN) O(1)
class Solution {
 public:
  int findInMountainArray(int tgt, MountainArray &A) {
    int n = A.length();
    int lo = 0, hi = n-1, mi, peak = 0;
    // Find index of peak
    while (lo < hi) {
      mi = lo + (hi - lo) / 2;
      if (A.get(mi) < A.get(mi+1)) {
        lo = peak = mi + 1;
      } else {
        hi = mi;
      }
    }
    // Find target in the left of peak
    lo = 0;
    hi = peak;
    while (lo <= hi) {
      mi = lo + (hi - lo) / 2;
      if (A.get(mi) < tgt) {
        lo = mi + 1;
      } else if (A.get(mi) > tgt) {
        hi = mi - 1;
      } else {
        return mi;
      }
    }
    // Find target in the right of peak
    lo = peak;
    hi = n - 1;
    while (lo <= hi) {
      mi = lo + (hi - lo) / 2;
      if (A.get(mi) > tgt) {
        lo = mi + 1;
      } else if (A.get(mi) < tgt) {
        hi = mi - 1;
      } else {
        return mi;
      }
    }
    return -1;
  }
};
