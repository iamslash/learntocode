/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//   0 a b c d e
// 0 0 0 0 0 0 0
// a 0 1 1 1 1 1
// c 0 1 1 2 2 2
// e 0 1 1 2 2 3

// 16ms 57.27% 14.8MB 100.00%
// dynamic programming
// O(HW) O(HW)
class Solution {
 public:
  int longestCommonSubsequence(std::string a, std::string b) {
    int h = a.size(), w = b.size();
    std::vector<std::vector<int>> C(h+1, std::vector<int>(w+1));
    for (int y = 1; y <= h; ++y) {
      for (int x = 1; x <= w; ++x) {
        if (a[y-1] == b[x-1]) {
          C[y][x] = C[y-1][x-1] + 1;
        } else {
          C[y][x] = std::max(C[y][x-1], C[y-1][x]);
        }
      }
    }
    return C[h][w];
  }
};

int main() {
  return 0;
}
