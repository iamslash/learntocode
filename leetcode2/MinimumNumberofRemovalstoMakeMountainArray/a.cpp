/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

// nums: 4 3 2 1 1 2 3 1
// stck: 4 3 1
// stck: 1 

// 40ms 82.61% 12.8MB 15.52%
class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size(), ans = n;
    vector<int> lis(n), lds(n), V;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      auto it = lower_bound(V.begin(), V.end(), x);
      lis[i] = it - V.begin();
      if (it != V.end()) {
        *it = x;
      } else {
        V.push_back(x);
      }
    }
    V.clear();
    for (int i = n-1; i >= 0; --i) {
      int x = nums[i];
      auto it = lower_bound(V.begin(), V.end(), x);
      lds[i] = it - V.begin();
      if (it != V.end()) {
        *it = x;
      } else {
        V.push_back(x);
      }
    }
    for (int i = 1; i < n; ++i) {
      if (lis[i] && lds[i]) {
        ans = min(ans, n - (lis[i] + lds[i] + 1));
      }
    }
    return ans;
  }
};
