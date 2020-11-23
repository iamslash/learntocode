/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // 640ms 15.72% 15.2MB 80.29%
// // brute force
// // O(HWHW) O(1)
// class Solution {
//  public:
//   int countCornerRectangles(std::vector<std::vector<int>>& G) {
//     int h = G.size();
//     int w = G[0].size();
//     int r = 0;
//     for (int y = 0; y < h-1; ++y) {
//       for (int x = 0; x < w-1; ++x) {
//         // printf("%d %d\n", y, x);
//         for (int i = y + 1; i < h && G[y][x]; ++i) {
//           for (int j = x + 1; j < w && G[i][x]; ++j) {
//             // printf("  %d %d %d %d\n", y, x, i, j);
//             r += G[i][j] && G[y][j];
//           }
//         }
//       }
//     }
//     return r;
//   }
// };

// 188ms 74.95% 15MB 86.51%
// combination
//  O(HWW) O(1)
class Solution {
 public:
  int countCornerRectangles(std::vector<std::vector<int>>& G) {
    int r = 0;
    int h = G.size(), w = G[0].size();
    for (int i = 0; i < h - 1; ++i) {
      for (int j = i + 1; j < h; ++j) {
        int cnt = 0;
        for (int x = 0; x < w; ++x) {
          if (G[i][x] && G[j][x])
            cnt++;
        }
        if (cnt > 0)
          r += cnt * (cnt - 1) / 2;
      }
    }
    return r;
  }
};

int main() {
  // std::vector<std::vector<int>> G ={
  //   {1, 0, 0, 1, 0},
  //   {0, 0, 1, 0, 1},
  //   {0, 0, 0, 1, 0},
  //   {1, 0, 1, 0, 1}
  // };
  std::vector<std::vector<int>> G = {
    {1, 1, 1},
    {1, 1, 1},
    {1, 1, 1}
  };
  Solution sln;
  printf("%d\n", sln.countCornerRectangles(G));
  return 0;
}
