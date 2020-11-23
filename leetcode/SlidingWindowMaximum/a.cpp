/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

//    k: 3
//       i
// nums: 1 3 -1 -3 5 3 6 7
//  deq: 
//  ans: 

// 368ms 64.59% 106.9MB 55.67%
// sliding window, double ended queue
// O(N) O(N)
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> deq;
    for (int i = 0; i < nums.size(); ++i) {
      // make deq descending
      while (deq.size() > 0 && nums[deq.back()] < nums[i])
        deq.pop_back();
      deq.push_back(i);
      // push max value
      if (deq.size() > 0 && i >= k-1)
        ans.push_back(nums[deq.front()]);
      // remove num out of window
      while (deq.size() > 0 && deq.front() <= i-k+1)
        deq.pop_front();
    }
    return ans;
  }
};
