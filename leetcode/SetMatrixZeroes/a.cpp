// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/777/

#include <cstdio>
#include <vector>
#include <algorithm>

// 0, 1, 2, 0
// 3, 4, 5, 2
// 1, 3, 1, 5

// 0, 0, 0, 0
// 0, 4, 5, 0
// 0, 3, 1, 0

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& M) {
    int m = M.size();
    int n = m > 0 ? M[0].size() : 0;
    if (m == 0 || n == 0)
      return;
    bool b_top_z = false;
    bool b_left_z = false;

    // save top most, left most line
    if (std::any_of(std::begin(M[0]), std::end(M[0]), [](int i){return i==0;}))
      b_top_z = true;
    for (int y = 0; y < m; ++y) {
      if (M[y][0] == 0) {
        b_left_z = true;
        break;
      }
    }

    // loop entire lines except top, left lines
    for (int y = 1; y < m; ++y) {
      for (int x = 1; x < n; ++x) {
        if (M[y][x] == 0) {
          M[y][0] = 0;
          M[0][x] = 0;
        }
      }
    }

    // loop entire lines except top, left lines
    for (int y = 1; y < m; ++y) {
      for (int x = 1; x < n; ++x) {
        if (M[0][x] == 0 || M[y][0] == 0) {
          M[y][x] = 0;
        }
      }
    }
       
    // load save top most, left most zero
    if (b_top_z)
      std::fill(std::begin(M[0]), std::end(M[0]), 0);
    if (b_left_z) {
      for (int y = 0; y < m; ++y) {
        M[y][0] = 0;
      }
    }
  }
};

int main() {
  // [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
  std::vector<std::vector<int>> v = {
    {0, 1, 2, 0},
    {3, 4, 5, 2},
    {1, 3, 1, 5}
  };

  Solution s;
  s.setZeroes(v);

  // print v
  for (const auto& a : v) {
    for (int b : a) {
      printf("%d, ", b);
    }
    printf("\n");
  }

  return 0;
}
