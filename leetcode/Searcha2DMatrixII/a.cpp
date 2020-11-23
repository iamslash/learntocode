/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/806/

#include <cstdio>
#include <vector>

// 1 4 7
// 2 5 8
// 3 6 9
// 
class Solution {
 public:
  bool searchMatrix(std::vector<std::vector<int>>& v, int t) {
    if (v.empty() || v[0].empty())
      return false;

    // traverse from (0, n-1)
    int m = v.size(), n = v[0].size();
    int y = 0, x = n - 1;

    while (y < m && x >= 0) {
      if (v[y][x] == t)
        return true;
      else if (t < v[y][x])
        --x;
      else
        ++y;
    }
    
    return false;
  }
};

int main() {
  std::vector<std::vector<int>> m = {
    {1, 4, 7, 11, 15},
    {2, 5, 8, 12, 19},
    {3, 6, 9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30},
  };
  int t = 20;
  
  Solution s;
  printf("%s\n", s.searchMatrix(m, t) ? "true" : "false");
  
  return 0;
}
