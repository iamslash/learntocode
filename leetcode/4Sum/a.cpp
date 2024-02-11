/* Copyright (C) 2024 by iamslash */

#include <cstdio>
#include <vector>
#include <set>

using namespace std;

// 27ms 72.20% 16.2MB 27.29%
// two pointers
// O(N^3) O(N)
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 3; ++i) {
      for (int j = i+1; j < n - 2; ++j) {
        // Skip same nums[j]
        if (j > i + 1 && nums[j] == nums[j-1]) {
          continue;
        }
        int l = j + 1, r = n - 1;
        while (l < r) {
          long sum = nums[i];
          sum += nums[j];
          sum += nums[l]; 
          sum += nums[r];
          if (sum == target) {
            ans.insert({nums[i], nums[j], nums[l], nums[r]});
            ++l;
            while (l < r && nums[l - 1] == nums[l]) {
              ++l;
            }
            --r;
            while (l < r && nums[r] == nums[r + 1]) {
              --r;
            }
          } else if (sum < target) {
            ++l;
          } else {
            --r;
          }
        }
      }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
  }
};

int main() {
  return 0;
}
