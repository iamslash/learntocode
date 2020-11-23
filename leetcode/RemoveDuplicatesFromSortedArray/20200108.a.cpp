/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
      auto it = std::unique(nums.begin(), nums.end());
      nums.erase(it, nums.end());
      return nums.size();
    }
};

int main() {
  Solution s;
  std::vector<int> v = {1, 1, 2};
  printf("%d\n", s.removeDuplicates(v));
  for (int n : v) {
    printf("%d ", n);
  }
  printf("\n");         
  return 0;
}
