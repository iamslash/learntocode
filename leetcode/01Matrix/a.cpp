/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>
// {0, 0, 0},
// {0, 1, 0},
// {1, 1, 1}

// {0, 0, 0},
// {0, 1, 0},
// {M, M, M}

    // {0,1,0,1,1}
    // {1,1,0,0,1}
    // {0,0,0,1,0}
    // {1,0,1,1,1}
    // {1,0,0,0,1}

    // {0,1,0,1,2}
    // {1,2,0,0,1}
    // {0,0,0,1,0}
    // {1,0,1,2,1}
    // {2,0,0,0,1}

    // {0,1,0,1,2}
    // {1,1,0,0,1}
    // {0,0,0,1,0}
    // {1,0,1,1,1}
    // {1,0,0,0,1}

// 188ms 56.99%
// O(HW) O(HW)
class Solution {
 public:
  std::vector<std::vector<int>> updateMatrix(
      std::vector<std::vector<int>>& M) {
    int h = M.size();
    int w = M[0].size();
    std::vector<std::vector<int>> R(
        h,
        std::vector<int>(w, std::numeric_limits<int>::max()));
    int dy[4] = {-1, 0, 1,  0};
    int dx[4] = { 0, 1, 0, -1};
    for (int z = 0; z <= 1; ++z) {
      for (int y = z ? h-1 : 0; z ? y >= 0 : y < h; z ? --y : ++y) {
        for (int x = z ? w-1 : 0; z ? x >= 0 : x < w; z ? --x : ++x) {
          if (M[y][x] == 0) {
            R[y][x] = 0;
          } else {
            for (int i = 0; i < 4; ++i) {
              int ny    = y + dy[i];
              int nx    = x + dx[i];
              if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;
              if (R[ny][nx] != std::numeric_limits<int>::max() &&
                  R[y][x] > R[ny][nx] + 1)
                R[y][x] = R[ny][nx] + 1;
            }
          }
        }
      }
    }
    return R;
  }
};

int main() {
  // std::vector<std::vector<int>> M = {
  //   {0, 0, 0},
  //   {0, 1, 0},
  //   {1, 1, 1}
  // };
  std::vector<std::vector<int>> M = {
    {0,1,0,1,1},
    {1,1,0,0,1},
    {0,0,0,1,0},
    {1,0,1,1,1},
    {1,0,0,0,1}};
  Solution sln;
  auto rslt = sln.updateMatrix(M);
  for (const auto& l : rslt) {
    for (int a : l) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}
