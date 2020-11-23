/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// 2
// 3 4
// 6 5 7
// 4 1 8 3

// 11
// 9 10
// 7 6 10
// 4 1 8 3

// 8ms 94.01% 8.6MB 5.07%
// iterative dynamic programming
// O(N^2) 
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& T) {
    int n = T.size();
    if (n == 0)
      return 0;
    for (int y = n-1; y > 0; --y) {
      for (int x = 0; x < y; ++x) {
        T[y-1][x] += min(T[y][x], T[y][x+1]);
      }
    }
    return T[0][0];
  }
};
