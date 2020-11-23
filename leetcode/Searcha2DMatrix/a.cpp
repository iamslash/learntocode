/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/search-a-2d-matrix/description/

#include <cstdio>
#include <vector>

// O(N) O(1)
// 4ms 100%
#include <iostream>
static int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& M, int t) {
    if (M.empty() || M[0].empty())
      return false;
    int y = 0;
    int x = M[0].size()-1;
    while (y < M.size() &&
           x >= 0) {
      int a = M[y][x];

      if (t == a)
        return true;
      else if (t < a)
        --x;
      else
        ++y;
    }
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> M = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50},
  };
  // int t = 3;
  int t = 13;
  
  Solution s;
  printf("%s\n", s.searchMatrix(M, t) ? "true" : "false");
  
  return 0;
}
