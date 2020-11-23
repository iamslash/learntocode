/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/796/

#include <cstdio>
#include <vector>


// 1 2 3
//

// []
// 1
// 2
// 3
//
class Solution {
 public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> r;
    std::vector<int> v;

    int n = 1 << nums.size();  // subset size = 2**n
    for (int i = 0; i < n; ++i) {
      v.clear();
      // check bit field
      for (int j = 0; j < nums.size(); ++j) {
        if (i & (1 << j)) {
          v.push_back(nums[j]);
        }
      }
      r.push_back(v);
    }
    return r;
  }
};

int main() {
  std::vector<int> v = {1, 2, 3};
  Solution s;
  std::vector<std::vector<int>> r = s.subsets(v);
  for (const auto& rr : r) {
    for (int i : rr) {
      printf("%d ", i);
    }
    printf("\n");
  }  
  
  return 0;
}
