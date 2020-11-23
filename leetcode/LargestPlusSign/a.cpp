/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// l: 4
// r: 3
// u: 3
// d: 1
//
// 1 2 3 2 1
// 2 5 5 5 5
// 1 5 5 5 5
// 0 5 5 0 5
// 5 5 5 5 5

// Q. range of N
// Q. length of M
// 124ms 97.83% 30.2MB 83.33%
// forward-back traverse
// O(N^2) O(N^2)
class Solution {
 public:
  // 6: 3, 5: 3
  int orderOfLargestPlusSign(int N, std::vector<std::vector<int>>& M) {
    std::vector<std::vector<int>> C(N, std::vector<int>(N, N));
    for (auto& v : M)
      C[v[0]][v[1]] = 0;

    for (int y = 0; y < N; ++y) {
      int l = 0, r = 0, u = 0, d = 0;
      for (int j = 0, k = N - 1; j < N; ++j, --k) {
        l = C[y][j] == 0 ? 0 : l + 1;
        C[y][j] = std::min(C[y][j], l);
        r = C[y][k] == 0 ? 0 : r + 1;
        C[y][k] = std::min(C[y][k], r);
        u = C[j][y] == 0 ? 0 : u + 1;
        C[j][y] = std::min(C[j][y], u);
        d = C[k][y] == 0 ? 0 : d + 1;
        C[k][y] = std::min(C[k][y], d);
      }
    }
    int rslt = 0;
    for (int y = 0; y < N; ++y) {
      for (int x = 0; x < N; ++x) {
        rslt = std::max(rslt, C[y][x]);
      }
    }
    return rslt;
  }
};

int main() {
  // int N = 5;
  // std::vector<std::vector<int>> M = {{4, 2}};
  // int N = 2;
  // std::vector<std::vector<int>> M;
  // int N = 1;
  // std::vector<std::vector<int>> M = {{0, 0}};
  int N = 5;
  std::vector<std::vector<int>> M = {{3, 0}, {3, 3}};
  Solution sln;
  printf("%d\n", sln.orderOfLargestPlusSign(N, M));
  return 0;
}
