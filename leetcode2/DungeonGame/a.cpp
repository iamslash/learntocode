/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

// -2  -3  3 
// -5 -10  1 
// 10  30 -5 

//  7   5  2 M
//  6  11  5 M
//  1   1  6 1
//  M   M  1 M

// 20ms 12.89% 9MB 55.03%
// dynamic programming
// O(HW) O(HW)
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& G) {
    int h = G.size(), w = G[0].size();
    vector<vector<int>> C(h+1, vector<int>(w+1, INT_MAX));
    C[h][w-1] = 1;
    C[h-1][w] = 1;
    for (int y = h-1; y >= 0; --y) {
      for (int x = w-1; x >= 0; --x) {
        int need = min(C[y+1][x], C[y][x+1]) - G[y][x];
        if (need <= 0)
          need = 1;
        C[y][x] = need;
      }
    }
    return C[0][0];
  }
};
