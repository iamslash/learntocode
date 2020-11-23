/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <algorithm>
#include <vector>

class Solution {
public:
  int singleNumber(std::vector<int>& nums) {
    return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
  }
};

int main() {
  return 0;
}
