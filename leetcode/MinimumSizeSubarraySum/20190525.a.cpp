// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>

class Solution {
 public:
  int minSubArrayLen(int s, const std::vector<int>& nums) {
    if (nums.empty())
      return 0;
    // sliding window
    int l = 0, r = 0, rslt = std::numeric_limits<int>::max(), sum = 0;
    while (l <= r && r < nums.size()) {
      sum += nums[r];
      printf("l: %d r: %d sum: %d\n", l, r, sum);
      if (sum < s) {
        ++r;
      } else if (sum > s) {
        sum -= nums[l];
        sum -= nums[r];
        ++l;
      } else {
        rslt = std::min(rslt, r - l + 1);
        sum -= nums[l];
        ++l;
        ++r;
      }
    }
    return rslt == std::numeric_limits<int>::max() ? 0 : rslt;
  }
};

int main() {
  // std::vector<int> nums = {2, 3, 1, 2, 4, 3};
  std::vector<int> nums = {1, 2, 3, 4, 5};

  Solution sln;

  printf("%d\n", sln.minSubArrayLen(11, nums));
  
  return 0;
}
