/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//    k: 2
//             i
// nums: 3 5 2 6
// stck: 2 6

// 332ms 71.43% 99MB 14.29%
// monotone increasing stack
// O(N) O(N)
class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> stck;
    for (int i = 0; i < nums.size(); ++i) {
      while (stck.size() &&
             stck.back() > nums[i] &&
             stck.size() - 1 + nums.size() - i >= k) {
        stck.pop_back();
      }
      if (stck.size() < k) {
        stck.push_back(nums[i]);
      }
    }
    return stck;
  }
};
