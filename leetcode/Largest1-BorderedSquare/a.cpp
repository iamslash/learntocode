/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 16ms 75.02% 10.9MB 100.00%
// memoization
// O(HW) O(HW)
class Solution {
 public:
  int largest1BorderedSquare(std::vector<std::vector<int>>& G) {
    int h = G.size(), w = G[0].size(), ans = 0;
    std::vector<std::vector<int>> V(h, std::vector<int>(w));
    std::vector<std::vector<int>> H(h, std::vector<int>(w));
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 0)
          continue;
        V[y][x] = y == 0 ? 1 : V[y-1][x] + 1;
        H[y][x] = x == 0 ? 1 : H[y][x-1] + 1;
      }
    }
    for (int y = h-1; y >= 0; --y) {
      for (int x = w-1; x >= 0; --x) {
        int len = std::min(V[y][x], H[y][x]);
        while (len > ans) {
          if (V[y][x-len+1] >= len && H[y-len+1][x] >= len)
            ans = len;
          --len;
        }
      }    
    }
    return ans*ans;
  }
};

int main() {
  return 0;
}
