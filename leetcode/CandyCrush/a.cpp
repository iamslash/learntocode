/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 24ms 100.00% 10.1MB 72.57%
// brute force
// O(HHW) O(1)
class Solution {
 public:
  std::vector<std::vector<int>> candyCrush(
      std::vector<std::vector<int>>& G) {
    int h = G.size();
    int w = G[0].size();
    while (true) {
      bool bfound = false;
      for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
          int val = std::abs(G[y][x]);
          // eliminate horizontal lines
          if (x+2 < w) {
            if (val != 0 &&
                val == std::abs(G[y][x+1]) &&
                val == std::abs(G[y][x+2])) {
              G[y][x] = G[y][x+1] = G[y][x+2] = -val;
              bfound = true;
            }
          }
          // eliminate vertical lines
          if (y+2 < h) {
            if (val != 0 &&
                val == std::abs(G[y+1][x]) &&
                val == std::abs(G[y+2][x])) {
              G[y][x] = G[y+1][x] = G[y+2][x] = -val;
              bfound = true;
            }
          }
        }
      }
      if (!bfound)
        break;
      // resolve
      for (int x = 0; x < w; ++x) {
        int whead = h-1;
        for (int rhead = h-1; rhead >= 0; --rhead) {
          if (G[rhead][x] > 0)
            G[whead--][x] = G[rhead][x];
        }
        while (whead >= 0)
          G[whead--][x] = 0;
      }
    }
    return G;
  }
};

void printg(std::vector<std::vector<int>>& G) {
  for (auto l : G) {
    for (int a : l) {
      printf("%4d ", a);
    }
    printf("\n");
  }
}

int main() {
  std::vector<std::vector<int>> G = {
    {110,5,112,113,114},
    {210,211,5,213,214},
    {310,311,3,313,314},
    {410,411,412,5,414},
    {5,1,512,3,3},
    {610,4,1,613,614},
    {710,1,2,713,714},
    {810,1,2,1,1},
    {1,1,2,2,2},
    {4,1,4,4,1014}
  };
  Solution sln;
  auto r = sln.candyCrush(G);
  printg(r);
  
  return 0;
}
