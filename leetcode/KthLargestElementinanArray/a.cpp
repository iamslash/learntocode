/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// 8ms 82.61% 10MB 60.06%
// sort
// O(NlgN) O(1)
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n-k];
  }
};

int main() {
  return 0;
}
