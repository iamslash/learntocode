/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

#define MAXVAL 1000000009
class Solution {
 public:
  int minimumIncompatibility(vector<int>& nums, int k) {
    int i, n = nums.size(), groupCnt = n / k;
    sort(nums.begin(), nums.end());
    vector<int> range(1 << n, MAXVAL);
    // build range, range[bm] = incompatibility
    for (int bm = 1; bm < (1 << n); ++bm) {
      int minNum = -1, maxNum = -1;
      bool dup = false;
      for (int i = 0; i < n && !dup; ++i) {
        if (bm & (1 << i)) {
          if (minNum == -1) {
            minNum = nums[i];
          }
          if (maxNum == nums[i]) {
            dup = true;
          }
          maxNum = nums[i];
        }
      }
      if (!dup) {
        range[bm] = maxNum - minNum;
      }
    }
    vector<int> C(1 << n, MAXVAL);
    C[0] = 0;
    for (int bm = 1; bm < (1 << n); ++bm) {
      for (int subBm = bm; subBm; subBm = (subBm - 1) & bm) {
        if (__builtin_popcount(subBm) == groupCnt) {
        }
      }
    }
    if (C.back() >= MAXVAL)
      return -1;
    return C.back();
  }
};
