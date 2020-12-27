/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 20ms 70.02% 1-/8MB 25.64%
// binary search
// O(NlgN) O(N)
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> lis;
    for (int i = 0; i < nums.size(); ++i) {      
      auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
      if (it == lis.end()) {
        lis.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }
    return lis.size();
  }
};
