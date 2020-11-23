/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 60ms 79.02% 12MB 87.50%
// O(HW) O(max(H,W))
class Solution {
 public:
  int findLonelyPixel(std::vector<std::vector<char>>& P) {
    if (P.empty() || P[0].empty())
      return 0;
    int h = P.size();
    int w = P[0].size();
    std::vector<int> xs(w, 0);
    std::vector<int> ys(h, 0);

    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (P[y][x] == 'B') {
          ys[y]++;
          xs[x]++;
        }
      }
    }
    int cnt = 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (P[y][x] == 'B' && ys[y] == 1 && xs[x] == 1)
          cnt++;
      }
    }    
    return cnt;
  }
};

int main() {

  // std::vector<std::vector<char>> G = {
  //   {'B','B','B'},
  //   {'B','B','B'},
  //   {'B','B','B'}
  // };

  std::vector<std::vector<char>> G ={
    {'B','W','W','W','W','B','W','B','B','W'},
    {'B','B','B','W','W','W','B','W','B','W'},
    {'B','B','B','B','W','W','W','B','W','W'},
    {'B','W','W','B','W','B','B','W','W','W'},
    {'W','W','B','W','B','B','B','W','B','B'},
    {'W','B','B','W','W','W','B','W','W','W'},
    {'B','W','W','B','B','B','W','W','W','W'},
    {'W','W','W','B','B','B','B','W','W','W'},
    {'W','W','B','B','W','W','W','W','B','W'},
    {'W','W','W','B','B','B','W','W','W','B'}};

  Solution sln;
  printf("%d\n", sln.findLonelyPixel(G));
  
  return 0;
}
