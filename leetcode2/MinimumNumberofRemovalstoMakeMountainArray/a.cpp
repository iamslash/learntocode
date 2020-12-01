/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// nums: 4 3 2 1 1 2 3 1
// stck: 4 3 1
// stck: 1 

class Solution {
 private:
  int lisAscCnt(vector<int>& nums, int topIdx) {
    vector<int> lis;
    for (int i = 0; i < topIdx; ++i) {
      if (nums[i] >= nums[topIdx]) {
        continue;
      }
      auto it = lower_bound(nums.begin(), nums.begin() + topIdx, nums[i]);
      if (it == lis.end()) {
        lis.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }
    return lis.size();
  }
  int lisDscCnt(vector<int>& nums, int topIdx) {
    int n = nums.size();
    vector<int> lis;
    for (int i = n-1; i > topIdx; --i) {
      if (nums[i] >= nums[topIdx]) {
        continue;
      }
      auto it = lower_bound(nums.rbegin(), nums.rbegin() + (n - topIdx), nums[i]);
      if (it == lis.rend()) {
        lis.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
    }
    return lis.size();
  }
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size(), ans = INT_MAX;
    for (int i = 1; i < n-1; ++i) {
      int mountainCnt = 1 +
          lisAscCnt(nums, i) +
          lisDscCnt(nums, i);
      ans = min(ans, n - mountainCnt);
    }
    if (ans == INT_MAX)
      return 0;
    return ans;
  }
};
