// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/801/

#include <cstdio>
#include <vector>
#include <limits>

class Solution {
 public:
  int findPeakElement(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int a = i == 0 ? std::numeric_limits<int>::min() : nums[i-1];
      int b = nums[i];
      int c = i == nums.size()-1 ? std::numeric_limits<int>::min() : nums[i+1];
      // printf("%lld %lld %lld\n", a, b, c);
      if (b == std::numeric_limits<int>::min()) {
        if (a <= b && b >= c)
          return i;
      } else {
        if (a < b && b > c)
          return i;
      }
    }
    return -1;
  }
};

int main() {
  // std::vector<int> v = {1, 2, 3, 1};
  // std::vector<int> v = {1};
  std::vector<int> v = {-2147483648};
  
  Solution s;
  printf("%d\n", s.findPeakElement(v));
  
  return 0;
}
