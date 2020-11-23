// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/maximal-square/description/

#include <cstdio>
#include <vector>

printvv(std::vector<std::vector<char>>& matrix) {
  int Y = matrix.size();
  int X = matrix[0].size();
  for (int y = 0; y < Y; ++y) {
    for (int x = 0; x < X; ++x) {
      printf("%d ", matrix[y][x]);
    }
    printf("\n");
  }
}


// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0


// using namespace std;

// int maximalSquare(vector<vector<char>>& matrix) { 
//     int m = matrix.size();
//     if (!m) return 0;
//     int n = matrix[0].size();
//     vector<vector<int> > size(m, vector<int>(n, 0));
//     int maxsize = 0;
//     for (int j = 0; j < n; j++) {
//         size[0][j] = matrix[0][j];
//         maxsize = max(maxsize, size[0][j]);
//     }
//     for (int i = 1; i < m; i++) {
//         size[i][0] = matrix[i][0];
//         maxsize = max(maxsize, size[i][0]);
//     }
//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             if (matrix[i][j] == 1) {
//                 size[i][j] = min(size[i - 1][j - 1], min(size[i - 1][j], size[i][j - 1])) + 1;
//                 maxsize = max(maxsize, size[i][j]);
//             }
//         }
//     }
//     return maxsize * maxsize;
// }

//
// a b
// c o
//
// 12ms 98.24%
class Solution {
 public:
  int maximalSquare(std::vector<std::vector<char>>& M) {
    int rslt = 0; // max square
    if (M.empty() || M[0].empty())
      return rslt;
    int h = M.size();
    int w = M[0].size();
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        int a = (y > 0 && x > 0) ? M[y-1][x-1] : 0;
        int b = (y > 0) ? M[y-1][x] : 0;
        int c = (x > 0) ? M[y][x-1] : 0;
        M[y][x] = (M[y][x] > '0') ? (std::min(a, std::min(b, c)) + 1) : 0;
        rslt = std::max(rslt, M[y][x] * M[y][x]);
      }
    }
    return rslt;
  }
};
  
int main() {
  std::vector<std::vector<char>> M = {
    {'1', '0', '1', '0', '0'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '1'},
    {'1', '0', '0', '1', '0'}
  };
  // print_vv(a);
  Solution sln;
  printf("%d\n", sln.maximalSquare(M));
  printvv(M);
  return 0;
}
