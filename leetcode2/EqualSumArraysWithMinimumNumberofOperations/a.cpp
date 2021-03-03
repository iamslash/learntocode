/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// 272ms 16.67% 126.9MB 33.33%
// sort
// O(NlgN) O(N)
class Solution {
 public:
  int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    if (sum1 > sum2) {
      swap(nums1, nums2);
      swap(sum1, sum2);
    }
    int ans = 0, diff = sum2 - sum1;
    if (diff == 0) {
      return 0;
    }
    vector<int> removes;
    for (int num : nums1) {
      removes.push_back(6 - num);
    }
    for (int num : nums2) {
      removes.push_back(num - 1);
    }
    sort(removes.rbegin(), removes.rend());
    for (int remove : removes) {
      ans++;
      diff -= remove;
      if (diff <= 0) {
        return ans;
      }
    }
    return -1;
  }
};
