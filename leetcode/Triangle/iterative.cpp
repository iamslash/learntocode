// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/triangle/description/

#include <cstdio>
#include <vector>
#include <algorithm>

// iterative way
// bottom up solution
// O(N^2) O(1)
// 4ms 99.25%
class Solution {
 public:
  int minimumTotal(std::vector<std::vector<int>>& B) {
    if (B.empty())
      return 0;
    for (int i = B.size()-1; i > 0; --i) {
      for (int j = 0; j < B[i].size() - 1; ++j) {
        // printf("%d %d\n", i, j);
        B[i-1][j] += std::min(B[i][j], B[i][j+1]);
      }
    }
    return B[0][0];
  }
};

int main() {
  std::vector<std::vector<int>> B = {
    {2},
    {3, 4},
    {6, 5, 7},
    {4, 1, 8, 3},
  };
  Solution s;
  printf("%d\n", s.minimumTotal(B));
  return 0;
}
