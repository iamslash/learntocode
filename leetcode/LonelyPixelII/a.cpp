/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// 76ms 44.62% 14.1MB 75.00%
// O(HW) O(max(H,W))
class Solution {
 public:
  int findBlackPixel(std::vector<std::vector<char>>& P, int N) {
    if (P.empty() || P[0].empty())
      return 0;
    int h = P.size();
    int w = P[0].size();
    std::vector<int> xs(w, 0);
    std::vector<int> ys(h, 0);
    std::unordered_map<int, std::vector<int>> brows;
    std::unordered_map<int, std::vector<int>> bcols;

    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (P[y][x] == 'B') {
          ys[y]++;
          xs[x]++;
          brows[x].push_back(y);
          bcols[y].push_back(x);
        }
      }
    }
    int cnt = 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (P[y][x] == 'B' && ys[y] == N && xs[x] == N) {
          bool b = true;
          for (int row : brows[x]) {
            if (bcols[row] != bcols[y]) {
              b = false;
              break;
            }
          }
          if (b) {
            printf("%d %d\n", y, x);
            cnt++;
          }
        }
      }
    }    
    return cnt;
  }
};

int main() {

  std::vector<std::vector<char>> P = {
      {'W', 'B', 'W', 'B', 'B', 'W'},    
      {'W', 'B', 'W', 'B', 'B', 'W'},    
      {'W', 'B', 'W', 'B', 'B', 'W'},    
      {'W', 'W', 'B', 'W', 'B', 'W'}
  };
  int N = 3;
  // std::vector<std::vector<char>> P = {
  //   {'W','B','B','W','W','B','W','W','W','W','W','B','B','W','W'},
  //   {'W','B','B','W','W','B','W','W','W','W','W','B','B','W','W'},
  //   {'W','W','W','W','W','B','B','B','W','B','W','W','W','W','B'},
  //   {'W','W','B','W','B','W','W','W','W','B','B','W','B','W','W'},
  //   {'W','B','B','W','W','B','W','W','W','W','W','B','B','W','W'},
  //   {'W','W','B','W','B','W','W','W','W','B','B','W','B','W','W'},
  //   {'W','W','B','W','B','W','W','W','W','B','B','W','B','W','W'},
  //   {'W','W','B','W','B','W','W','W','W','B','B','W','B','W','W'}};
  // int N = 5;
  Solution sln;
  printf("%d\n", sln.findBlackPixel(P, N));
  
  return 0;
}
