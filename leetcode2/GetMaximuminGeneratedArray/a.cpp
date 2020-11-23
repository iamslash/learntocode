/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// brute force
// O(N) O(N)
class Solution {
 public:
  int getMaximumGenerated(int n) {
    if (n == 0 || n == 1)
      return n;
    vector<int> nums(n+1);
    nums[1] = 1;
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
      if (i % 2 == 0) {
        nums[i] = nums[i/2];
      } else {
        int j = (i-1)/2;
        nums[i] = nums[j] + nums[j+1];
      }
      ans = max(ans, nums[i]);
      // printf("i: %d, nums[i]:%d, ans: %d\n", i, nums[i], ans);
    }
    return ans;
  }
};
