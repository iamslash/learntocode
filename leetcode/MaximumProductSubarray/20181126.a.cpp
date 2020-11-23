// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/maximum-product-subarray/description/

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
  int maxProduct(std::vector<int>& nums) {
      int ans = nums[0];
      int min = nums[0];
      int max = nums[0];

      printf("nums[%d]: %2d, min: %2d, max: %2d, ans: %2d\n", 0, nums[0], min, max, ans);

      for (int i = 1; i < nums.size(); ++i) {
        int x = min * nums[i];
        int y = max * nums[i];
        min = std::min(nums[i], std::min(x, y));
        max = std::max(nums[i], std::max(x, y));
        ans = std::max(ans, max);

        printf("nums[%d]: %2d, min: %2d, max: %2d, ans: %2d\n", i, nums[i], min, max, ans);
      }
      return ans;
    }
};

int main() {
  Solution s;
  // std::vector<int> v = {2, 3, -2, 4};
  // std::vector<int> v = {2, -3, -2, 4};
  // std::vector<int> v = {2, 0, 0, 4};
  std::vector<int> v = {0, 1, 2, 4};
  printf("%d\n", s.maxProduct(v));
}
