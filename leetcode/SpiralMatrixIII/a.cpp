// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>

// how to generate 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 steps
class Solution {
 public:
  std::vector<std::vector<int>> spiralMatrixIII(int R, int C, int r, int c) {
    std::vector<std::vector<int>> rslt = {{r, c}};
    int dy = 0, dx = 1, dt = 0;
    for (int i = 0; rslt.size() < R*C; ++i) {
      for (int j = 0; j < i/2+1; ++j) {
        r += dy;
        c += dx;
        if (0 <= r && r < R && 0 <= c && c < C)
          rslt.push_back({r, c});
      }
      dt = dy, dy = dx, dx = -dt;
    }
    return rslt;
  }
};


int main() {

  Solution sln;
  auto rslt = sln.spiralMatrixIII(5, 6, 1, 4);
  for (auto V : rslt) {
    printf("{%d, %d} ", V[0], V[1]);
  }
  printf("\n");
  return 0;
}
