// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/800/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>


// 3 2 1 5 6 4
// 6 5 4 3 2 1
class Solution {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    int r = -1;
    for (int i = 0; i < k; ++i) {
      // printf("%d %d\n", i, nums[i]);
      r = nums[i];
    }
    return r;
  }
};

int main() {
  std::vector<int> v = {3, 2, 1, 5, 6, 4};
  int k = 2;

  Solution s;
  printf("%d\n", s.findKthLargest(v, k));
}

