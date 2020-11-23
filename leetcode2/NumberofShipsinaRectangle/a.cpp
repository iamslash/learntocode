/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

class Sea {
 public:
  bool hasShips(vector<int> topRight, vector<int> bottomLeft);
};

// 40ms 76.4% 26.1MB 100.00%
// Divide and conquor, quard tree
// O(4^N) O(lg4N)
class Solution {
 private:
  int dfs(Sea sea, int x0, int x1, int y0, int y1) {
    if (x0 > x1 || y0 > y1 || !sea.hasShips({x1, y1}, {x0, y0}))
      return 0;
    if (x0 == x1 && y0 == y1)
      return 1;
    int xm = (x0 + x1) / 2;
    int ym = (y0 + y1) / 2;
    return dfs(sea, x0, xm, y0, ym) +
        dfs(sea, xm+1, x1, y0, ym) +
        dfs(sea, x0, xm, ym+1, y1) +
        dfs(sea, xm+1, x1, ym+1, y1);
  }
 public:
  int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
    return dfs(sea, bottomLeft[0], topRight[0],
               bottomLeft[1], topRight[1]);
  }
};
