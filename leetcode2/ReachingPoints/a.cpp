/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// . . . .
// . . o .
// . x . .
// . . . .

// 0ms 100.00% 5.9MB 83.76%
// euclidean
class Solution {
 private:
  bool dfs(int sx, int sy, int tx, int ty) {
    // base
    if (tx < sx)
      return false;
    if (tx == sx) {
      if (ty >= sy) {
        return ((ty - sy) % tx) == 0;
      } else {
        return false;
      }
    }
    return dfs(sy, sx, ty % tx, tx);
  }
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    if (tx < ty) {
      return dfs(sx, sy, tx, ty);
    }
    return dfs(sy, sx, ty, tx);
  }
};
