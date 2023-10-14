/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <unordered_set>

using namespace std;

// 6ms 40.99% 19.1MB 78.28%
// hash set
// O(N) O(N)
class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    int n = nums.size();    
    unordered_set<int> numSet;
    for (int i = n-1; i >= 0; --i) {
      if (nums[i] <= k) {
        numSet.insert(nums[i]);
      }
      if (numSet.size() == k) {
        return n - i;
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
