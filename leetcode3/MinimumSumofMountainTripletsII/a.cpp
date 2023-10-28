/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;

//                  i
//      nums: 8 6 1 5 3
//  leftMins: 8 6 1 1 1
// rightMins: 1 1 1 3 3

// 3ms 92.34% 21.2MB 34.47%
// hash map
// O(N) O(N)
class Solution {
public:
  int minimumSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftMins(n, nums[0]), rightMins(n, nums[n-1]);
    for (int i = 1; i < n; ++i) {
      leftMins[i] = min(leftMins[i-1], nums[i]);
    }
    for (int i = n-2; i >= 0; --i) {
      rightMins[i] = min(nums[i], rightMins[i+1]);
    }
    int minSum = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (leftMins[i] < nums[i] && nums[i] > rightMins[i]) {
        minSum = min(minSum, leftMins[i] + nums[i] + rightMins[i]);
      }
    }
    return minSum == INT_MAX ? -1 : minSum;
  }
};

int main() {
  return 0;
}
