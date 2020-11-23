/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 32ms 99.59% 10.8MB 100.00%
// O(HW) O(W)
class Solution {
 public:
  int maxKilledEnemies(std::vector<std::vector<char>>& G) {
    if (G.empty() || G[0].empty())
      return 0;
    int h = G.size();
    int w = G[0].size();
    int rslt = 0, killrow, killcol[w];
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (!x || G[y][x-1] == 'W') {
          killrow = 0;
          for (int k = x; k < w && G[y][k] != 'W'; ++k)
            killrow += G[y][k] == 'E';
        }
        if (!y || G[y-1][x] == 'W') {
          killcol[x] = 0;
          for (int k = y; k < h && G[k][x] != 'W'; ++k)
            killcol[x] += G[k][x] == 'E';
        }
        if (G[y][x] == '0')
          rslt = std::max(rslt, killrow + killcol[x]);
      }
    }
    return rslt;
  }
};

// 1 2 0 1 : killcol
// 2      : killrow

// 0 E 0 0
// E 0 W E
// 0 E 0 0

// rslt : 3

int main() {
  std::vector<std::vector<char>> G = 
  {
    {'0','E','0','0'},
    {'E','0','W','E'},
    {'0','E','0','0'}
  };
  Solution sln;
  printf("%d\n", sln.maxKilledEnemies(G));
  return 0;
}
