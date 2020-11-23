/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

// 0ms 100.00% 6.4MB 29.71%
// binary search
class Solution {
 public:
  string smallestGoodBase(string n) {
    uint64_t num = stol(n);
    for (uint64_t len = log(num+1) / log(2); len >= 2; --len) {
      uint64_t lo = 2, hi = pow(num, 1.0 / (len-1)) + 1;
      while (lo < hi) {
        uint64_t mi = lo + (hi - lo) / 2;
        uint64_t sum = 0;
        uint64_t val = 1;
        for (uint64_t i = 0; i < len; ++i, val *= mi) {
          sum += val;
        }
        if (sum < num) {
          lo = mi + 1;
        } else if (sum > num) {
          hi = mi;
        } else {
          return to_string(mi);
        }
      }
    }
    return to_string(num - 1);
  }
};
