// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/google/59/array-and-strings/338/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& m) {
    std::vector<int> r;
    // check empty matrix
    int ny = m.size();
    if (ny == 0)
      return r;
    int nx = m[0].size();
    if (nx == 0)
      return r;
    int nyx = ny * nx;

    // for (const auto& row : m) {
    //   for (const auto& e : row) {
    //     printf("%d ", e);
    //   }
    //   printf("\n");
    // }
    // traverse
    int ys = 0, ye = ny, xs = 0, xe = nx;  // start y, end y, start x, end x
    int y = 0, x = 0, dy = 0, dx = 0;
    // while (y >= ys && y < ye && x >= xs && x < xe) {
    while (ys <= ye && xs <= xe && r.size() < nyx) {
      r.push_back(m[y][x]);
      if (y == ys && x == xs)
        ys++, dy = 0, dx = 1;
      else if (x == xe - 1 && dy == 0 && dx > 0)
        xe--, dy = 1, dx = 0;
      else if (y == ye - 1 && dy > 0 && dx == 0)
        ye--, dy = 0, dx = -1;
      else if (x == xs && dy == 0 && dx < 0)
        xs++, dy = -1, dx = 0;
      else if (y == ys && dy < 0 && dx == 0)
        ys++, dy = 0, dx = 1;
      // printf("m:%d y:%d x:%d ys:%d ye:%d xs:%d xe:%d dy:%d dx:%d\n",
      //        m[y][x], y, x, ys, ye, xs, xe, dy, dx);
      y += dy;
      x += dx;
    }
    return r;
  }
};

int main() {
  // std::vector<std::vector<int>> m;
  // m.emplace_back(std::vector<int>{1, 2, 3});
  // m.emplace_back(std::vector<int>{3, 4, 5});
  // m.emplace_back(std::vector<int>{6, 7, 8});

  std::vector<std::vector<int>> m = {{1, 2, 3},
                                     {4, 5, 6},
                                     {7, 8, 9}};
  Solution s;
  std::vector<int> r = s.spiralOrder(m);
  for (int x : r) {
    printf("%d ", x);
  }
  printf("\n");
  return 0;
}
