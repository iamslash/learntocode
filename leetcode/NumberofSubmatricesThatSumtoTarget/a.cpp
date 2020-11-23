/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

void printG(std::vector<std::vector<int>>& G) {
  for (auto& row : G) {
    for (int a : row) {
      printf("%d ", a);
    }
    printf("\n");
  }
}

// 3956ms 82.20% 457.1MB 100.00%
// prefix sum
// O(HWW) O(HW)
class Solution {
 public:
  int numSubmatrixSumTarget(std::vector<std::vector<int>>& G, int T) {
    int h = G.size(), w = G[0].size();
    // set ps
    std::vector<std::vector<int>> psrow(
        h, std::vector<int>(w, 0));
    for (int y = 0; y < h; ++y) {
      psrow[y][0] = G[y][0];
      for (int x = 1; x < w; ++x) {
        psrow[y][x] = psrow[y][x-1] + G[y][x];
      }
    }

    // prefix sum of paring columns
    int r = 0;
    for (int i = 0; i < w; ++i) {
      for (int j = i; j < w; ++j) {
        std::unordered_map<int, int> s2c;  // sum : count
        s2c[0] = 1;
        int sum = 0;
        for (int y = 0; y < h; ++y) {
          sum += psrow[y][j] - (i > 0 ? psrow[y][i-1] : 0);
          int X = sum - T;
          if (s2c.count(X))
            r += s2c[X];
          s2c[sum]++;
        }
      }
    }
    return r;
  }
};

int main() {
  // std::vector<std::vector<int>> M = {{0,1,0},{1,1,1},{0,1,0}};
  // int T = 0;
  // std::vector<std::vector<int>> M = {{1,-1},{-1,1}};
  // int T = 0;
  std::vector<std::vector<int>> M = {{0,1,0,0,1},{0,0,1,1,1},{1,1,1,0,1},{1,1,0,1,1},{0,1,1,0,0}};
  int T = 1;
  Solution sln;
  printf("%d\n", sln.numSubmatrixSumTarget(M, T));
  
  return 0;
}
