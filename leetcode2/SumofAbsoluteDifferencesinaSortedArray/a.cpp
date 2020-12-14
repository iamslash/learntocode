/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// Time Limit Exceeded
// brute force
// O(N^2) O(N)
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      int absDiff = 0;
      for (int j = 0; j < n; ++j) {
        absDiff += abs(nums[i] - nums[j]);
      }
      ans[i] = absDiff;
    }
    return ans;
  }
};

//          j
// nums:  1 4 6 8 10
//  ans: 24 + 3

// 204ms 14.29% 83.6MB 14.29%
// prefix sum
// O(N) O(N)
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 1; i < n; ++i) {
      ans[0] += (nums[i] - nums[0]);
    }
    for (int j = 1; j < n; ++j) {
      int diff = nums[j] - nums[j-1];
      ans[j] = ans[j-1] + (diff * j) - (diff * (n - j));
    }
    return ans;
  }
};
