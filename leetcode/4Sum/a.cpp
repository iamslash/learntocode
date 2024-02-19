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

// 11ms 90.18% 19.3MB 26.53%
// two pointers
// O(N^3) O(N)
class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, long long target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    findNSum(nums, 0, nums.size() - 1, target, 4, {}, ans);
    return ans;
  }

private:
  void findNSum(vector<int>& nums, int left, int right, long long target, int N,
                vector<int> path, vector<vector<int>>& result) {
    if (right - left + 1 < N || N < 2 ||
        target < static_cast<long long>(nums[left]) * N ||
        target > static_cast<long long>(nums[right]) * N) {
      return;
    }

    // base
    if (N == 2) {
      while (left < right) {
        long long sum = static_cast<long long>(nums[left]) + nums[right];
        if (sum == target) {
          result.push_back(path);
          result.back().push_back(nums[left]);
          result.back().push_back(nums[right]);
          left++;
          while (left < right && nums[left] == nums[left - 1]) left++;
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
      return;
    }

    // recursion
    for (int i = left; i <= right; i++) {
      if (i == left || (i > left && nums[i - 1] != nums[i])) {
        vector<int> newPath(path);
        newPath.push_back(nums[i]);
        findNSum(nums, i + 1, right, target - nums[i], N - 1, newPath, result);
      }
      // Important: Skip duplicates in the outer loop as well
      while (i < right && nums[i] == nums[i + 1]) {
        i++;
      }
    }
  }
};


int main() {
  return 0;
}
