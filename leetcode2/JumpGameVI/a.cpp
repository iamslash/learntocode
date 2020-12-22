/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

//    k: 2
//               i
// nums: 1 -1 -2 4 -7 3
//                    j
//    C: 1  0 -1 5 -2 8

// iterative dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> C(n, INT_MIN);
    C[0] = nums[0];
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= k && i + j < n; ++j) {
        C[i+j] = max(C[i+j], C[i] + nums[i+j]);
        if (nums[i+j] >= 0)
          break;
      }
    }
    return C.back();                                
  }
};

// mono deque
// O(N) O(N)
class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> deq{0};
    for (int i = 1; i < n; ++i) {
      if (deq.front() + k < i) {
        deq.pop_front();
      }
      nums[i] += nums[d.front()];
      while (!deq.empty() && nums[deq.back()] <= nums[i]) {
        deq.pop_back();
      }
      deq.push_back(i);
    }
    return nums.back();                                
  }
};
