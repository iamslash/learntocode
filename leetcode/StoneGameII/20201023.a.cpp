/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

// 4ms 90.68% 8.9MB 100.00%
// recursive dynamic programming
// O(N^3) O(N^2)
class Solution {
 private:
  int dfs(std::vector<int>& P,
          std::vector<std::vector<int>>& C,
          int i, int M, int left) {
    int n = P.size();

    // memo
    int& r = C[i][M];
    if (r >= 0)
      return r;

    // recursion
    r = 0;
    int taken = 0;
    int bound = std::min(n, i + 2 * M);
    for (int j = i; j < bound; ++j) {
      taken += P[j];
      int nM = std::max(M, j - i + 1); //  X = j - i + 1
      r = std::max(r, left - dfs(P, C, j + 1, nM, left - taken));
    }
    return r;
  }
 public:
 int stoneGameII(std::vector<int>& P) {
    int n = P.size();
    std::vector<std::vector<int>> C(n+1, std::vector<int>(n+1, -1));
    int leftstone = std::accumulate(P.begin(), P.end(), 0);
    return dfs(P, C, 0, 1, leftstone);
  }
};

// // 16ms 37.33% 8.9Mb 100.00%
// // iterative dynamic programming
// // O(N^3) O(N^2)
// class Solution {
//  public:
//   int stoneGameII(std::vector<int>& P) {
//     int n = P.size();
//     std::vector<std::vector<int>> C(n+1, std::vector<int>(n+1, 0));
//     std::vector<int> ps(n+1, 0);
//     for (int i = n - 1; i >= 0; --i)
//       ps[i] = ps[i+1] + P[i];
//     for (int i = 0; i <= n; ++i)
//       C[i][n] = ps[i];
//     for (int i = n - 1; i >= 0; --i) {
//       for (int M = n - 1; M >= 1; --M) {
//         for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
//           C[i][M] = std::max(C[i][M], ps[i] - C[i+X][std::max(M, X)]);
//         }
//       }
//     }
//     return C[0][1];
//   }
// };

int main() {
  return 0;
}
