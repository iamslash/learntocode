/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <algorithm>

class Solution {
public:
  bool containsDuplicate(std::vector<int>& nums) {
    int n =  nums.size();
    if (n <= 1)
      return false;
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < n; ++i) {
      if (nums[i] == nums[i-1])
        return true;
    }
    return false;
  }
};

int main() {
  return 0;
}
