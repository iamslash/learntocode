/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//     i
// 1 4 5 2 3

// 316ms 100.00% 99.1MB 100.00%
// sliding window
// O(N) O(K)
class Solution {
 public:
  vector<int> largestSubarray(vector<int>& nums, int k) {
    int maxIdx = 0;
    for (int i = 1; i + k <= nums.size(); ++i) {
      if (nums[maxIdx] < nums[i]) {
        maxIdx = i;
      }
      // printf("i: %d, maxIdx: %d\n", i, maxIdx);
    }
    vector<int> ans;
    for (int i = maxIdx; i < maxIdx + k; ++i) {
      ans.push_back(nums[i]);
    }
    return ans;
  }
};
