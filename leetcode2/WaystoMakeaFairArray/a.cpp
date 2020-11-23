/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//         i
//   nums: 2 1 6 4
//  psEvn: 2 2 8 8
//  psOdd: 0 1 1 5

// 280ms 60.00% 103.6MB 40.00%
// prefix sum
// O(N) O(N)
class Solution {
 public:
  int waysToMakeFair(vector<int>& nums) {
    int n = nums.size(), ans = 0, even = 0, odd = 0;
    vector<int> psEven(n+1), psOdd(n+1);
    for (int i = n-1; i >- 0; --i) {
      if (i % 2 == 0) {
        psEven[i] += nums[i];
      } else {
        psOdd[i] += nums[i];
      }
      psEven[i] += psEven[i+1];
      psOdd[i] += psOdd[i+1];
    }
    for (int i = 0; i < n; ++i) {
      ans += (even + psOdd[i+1]) == (odd + psEven[i+1]);
      if (i % 2 == 0) {
        even += nums[i];
      } else {
        odd += nums[i];
      }
    }
    return ans;
  }
};
