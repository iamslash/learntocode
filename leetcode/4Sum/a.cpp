/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/4sum/description/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>


class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& v, int t) {
    if (v.size() < 4)
      return std::vector<std::vector<int>>();
    std::set<std::vector<int>> rslt;
    int l, r, sum;
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size()-3; ++i) {
      for (int j = i+1; j < v.size()-2; ++j) {
        // check skip
        if (j > i + 1 && v[j] == v[j-1])
          continue;
        l = j + 1;
        r = v.size() - 1;
        while (l < r) {
          sum = v[i] + v[j] + v[l] + v[r];
          if (sum == t) {
            std::vector<int> rr = {v[i], v[j], v[l], v[r]};
            rslt.insert(rr);
            while (l < r && v[l] == v[l+1])
              ++l;
            while (l < r && v[r] == v[r-1])
              --r;
            ++l;
            --r;
          } else if (sum < t) {
            ++l;
          } else {
            --r;
          }
        }
      }
    }
    return std::vector<std::vector<int>>(rslt.begin(), rslt.end());
  }
};

int main() {
  // std::vector<int> v = {1, 0, -1, 0, -2, 2};
  // int t = 0;
  // std::vector<int> v = {-3, -2, -1, 0, 0, 1, 2, 3};
  // int t = 0;
  // std::vector<int> v = {};
  // int t = 0;
  std::vector<int> v = {1, 0, -1, 0, -2, 2};
  int t = 0;

  Solution s;
  auto r = s.fourSum(v, t);
  for (const auto& rr : r) {
    for (int rrr : rr) {
      printf("%2d ", rrr);
    }
    printf("\n");
  }
  return 0;
}
