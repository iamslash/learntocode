/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 288ms 42.86% 87.9% 28.57%
class Solution {
 public:
  int minMoves(vector<int>& nums, int limit) {
    vector<int> delta(2 * limit + 2);
    int n = nums.size();
    for (int i = 0; i < n/2; ++i) {
      int a = nums[i], b = nums[n-1-i];
      delta[2] += 2;
      delta[min(a, b)+1]--;
      delta[a + b]--;
      delta[a + b + 1]++;
      delta[max(a, b) + limit + 1]++;
    }
    int ans = 2 * n, cur = 0;
    for (int i = 2; i <= 2 * limit; ++i) {
      cur += delta[i];
      ans = min(ans, cur);
    }
    return ans;
  }
};
