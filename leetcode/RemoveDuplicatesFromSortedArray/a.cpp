/* Copyright (C) 2019 by iamslash */

#include <cstdio>

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
    if (size <= 1)
      return size;
    int p = 0, i = 0;
    for (i = 0; i < size - 1; ++i) {
      if (nums[i] != nums[i+1]) {
        nums[p] = nums[i];
        p++;
      }
    }
    nums[p] = nums[i];
    return p+1;
  }
};

int main() {
  return 0;
}
