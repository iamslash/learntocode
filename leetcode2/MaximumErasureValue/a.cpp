/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

//            i
//    nums: 4 2 4 5 6
//              j
// freqMap: 2 
//     sum: 2
//     ans: 6  

//              i
//    nums: 5 2 1 2 5 2 1 2 5
//                j
// freqMap: 2 1 
//     sum: 3 
//     ans: 8  

// 804ms 51.68% 127.7MB 35.92%
// two pointers
// O(N) O(N)
class Solution {
 public:
  int maximumUniqueSubarray(vector<int>& nums) {
    unordered_set<int> freqSet;
    int i = 0, j = 0, n = nums.size(), ans = 0, sum = 0;
    for (j = 0; j < n; ++j) {
      while (freqSet.count(nums[j]) > 0) {
        freqSet.erase(nums[i]);
        sum -= nums[i];
        ++i;
      }
      freqSet.insert(nums[j]);
      sum += nums[j];
      ans = max(ans, sum);
    }
    return ans;
  }
};
