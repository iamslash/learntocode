/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 88ms 61.02% 14.3MB 100.00%
// dynamic programming
// O(HW^2) O(HW^2)
class Solution {
 private:
  int dfs(int y, int x0, int x1, vector<vector<vector<int>>>& C, vector<vector<int>>& G) {
    int h = G.size(), w = G[0].size();
    if (y == h)
      return 0;
    // printf("y: %d, x0: %d, x1: %d\n", y, x0, x1);
    // memo
    int& r = C[y][x0][x1];
    if (r >= 0)
      return r;
    // recursion
    r = 0;
    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
        int ny = y+1, nx0 = x0+i, nx1 = x1+j;
        if (nx0 < 0 || nx0 >= w || nx1 < 0 || nx1 >= w)
          continue;
        r = max(r, dfs(ny, nx0, nx1, C, G));
      }
    }
    r += G[y][x0] + (x0 == x1 ? 0 : G[y][x1]);
    return r;
  }
 public:
  int cherryPickup(vector<vector<int>>& G) {
    int h = G.size(), w = G[0].size();
    vector<vector<vector<int>>> C(h, vector<vector<int>>(w, vector<int>(w, -1)));
    return dfs(0, 0, w-1, C, G);
  }
};
