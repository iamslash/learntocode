/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>
#include <cmath>
#include <iostream>

using namespace std;

// 58ms 98.67% 72.3MB 99.56%
// greedy
// O(N) O(1)
class Solution {
public:
  long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
    // speedup code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = nums1.size();
    int64_t up = 0, dn = 0;

    // k == 0
    if (k == 0) {
      for (int i = 0; i < n; ++i) {
        if (nums1[i] != nums2[i]) {
          return -1;
        }
      }
      return 0;
    }

    // k > 0
    for (int i = 0; i < n; ++i) {
      int diff = abs(nums1[i] - nums2[i]);
      if (diff % k > 0) {
        return -1;
      }
      int quo = diff / k;
      if (nums1[i] > nums2[i]) {
        up += quo;
      } else if (nums1[i] < nums2[i]) {
        dn += quo;
      }
    }
    
    return up == dn ? up : -1;
  }
};
