/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/795/

#include <cstdio>
#include <vector>
#include <algorithm>

// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 2 1
// 3 1 2

class Solution {
 public:
  std::vector<std::vector<int>> r;
  void _solve(std::vector<int>& nums, int idx) {
    
    // base condition
    if (idx == nums.size()) {
      r.push_back(nums);
      return;
    }

    // for (int i = 0; i < idx; ++i)
    //   printf(" ");
    // printf("%d : ", idx);
    // for (int i = 0; i < nums.size(); ++i)
    //   printf("%d ", nums[i]);
    // printf("\n");

    // recursion
    for (int i = idx; i < nums.size(); ++i) {
      std::swap(nums[i], nums[idx]);
      _solve(nums, idx+1);
      std::swap(nums[i], nums[idx]);      
    }
  }
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    _solve(nums, 0);
    return r;
  }
}; 

int main() {
  std::vector<int> v = {1, 2, 3};
  Solution s;
  std::vector<std::vector<int>> r = s.permute(v);
  for (const auto& rr : r) {
    for (int n : rr) {
      printf("%d ", n);
    }
    printf("\n");
  }
  return 0;
}
