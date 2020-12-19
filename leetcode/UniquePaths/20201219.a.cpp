/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 0ms 100.00%
// recursive dynamic programming
// O(HW) O(HW)
class Solution {
 private:
  int dfs(vector<vector<int>>& C, int y, int x) {
    int h = C.size(), w = C[0].size();
    // base
    if (y < 0 || y >= h || x < 0 || x >= w)
      return 0;
    if (y == h-1 && x == w-1)
      return 1;
    // memo
    int& r = C[y][x];
    if (r >= 0)
      return r;
    // recursion
    r = dfs(C, y+1, x) + dfs(C, y, x+1);
    return r;
  }
 public:
  int uniquePaths(int h, int w) {
    vector<vector<int>> C(h, vector<int>(w, -1));
    return dfs(C, 0, 0);
  }
};

// 0ms 100.00% 7MB 43.46%
// iterative dynamic programming
// O(HW) O(HW)
class Solution {
 public:
  int uniquePaths(int h, int w) {
    vector<vector<int>> C(h, vector<int>(w));
    C[0][0] = 1;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (y > 0)
          C[y][x] += C[y-1][x];
        if (x > 0)
          C[y][x] += C[y][x-1];
      }
    }
    return C[h-1][w-1];
  }
};
