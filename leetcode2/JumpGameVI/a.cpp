/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

//    k: 2
//                  i
// nums: 1 -1 -2 4 -7 3
//                    j
//    C: 1  0 -1 4 -3 7

// 188ms 93.67% 58.5MB 76.50%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> C(n, INT_MIN);
    C[0] = nums[0];
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j <= min(i+k, n-1); ++j) {
        C[j] = max(C[j], C[i] + nums[j]);
        if (nums[j] >= 0)
          break;
      }
    }
    return C.back();                                
  }
};


//    k: 2
// nums: 1 -1 -2 4 -7 3
//                      i
//    C: 1  0 -2 2  5 7
//       
//  deq: 5

// 212ms 80.18% 57.1MB 86.44%
// monotone decreasing deque, sliding window
// O(N) O(K)
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> deq{0};
    for (int i = 1; i < n; ++i) {
      if (deq.front() + k < i) {
        deq.pop_front();
      }
      nums[i] += nums[deq.front()];
      while (!deq.empty() && nums[deq.back()] <= nums[i]) {
        deq.pop_back();
      }
      deq.push_back(i);
    }
    return nums.back();                                
  }
};
