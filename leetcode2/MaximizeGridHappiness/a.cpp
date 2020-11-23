/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <algorithm>

using namespace std;

// 360ms 74.54% 28.4MB 24.60%
// recursive dynamic programming
class Solution {
 private:
  int C[25][7][7][64][64] = {};
  int nCost(int h, int w, int y, int x, int inBm, int exBm, int d) {
    int diff = 0, up = 1 << (w - 1);
    if (x > 0 && (inBm & 1))
      diff += d - 30;
    if (y > 0 && (inBm & up))
      diff += d - 30;
    if (x > 0 && (exBm & 1))
      diff += d + 20;
    if (y > 0 && (exBm & up))
      diff += d + 20;
    return diff;
  }
  int dfs(int h, int w, int p, int inCnt, int exCnt, int inBm, int exBm) {
    // base
    int y = p / w, x = p % w;
    if (y >= h)
      return 0;
    int& r = C[p][inCnt][exCnt][inBm][exBm];
    if (r)
      return r - 1;
    int nInBm = (inBm << 1) & 63, nExBm = (exBm << 1) & 63;
    r = dfs(h, w, p+1, inCnt, exCnt, nInBm, nExBm);
    if (inCnt > 0) {
      int diff = 120 + nCost(h, w, y, x, inBm, exBm, -30);
      r = max(r, diff + dfs(h, w, p+1, inCnt-1, exCnt, nInBm+1, nExBm));
    }
    if (exCnt > 0) {
      int diff = 40 + nCost(h, w, y, x, inBm, exBm, 20);
      r = max(r, diff + dfs(h, w, p+1, inCnt, exCnt-1, nInBm, nExBm+1));
    }
    r = r + 1;
    return r - 1;
  }
 public:
  int getMaxGridHappiness(int h, int w, int inCnt, int exCnt) {
    return dfs(h, w, 0, inCnt, exCnt, 0, 0);
  }
};
