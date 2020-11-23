/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // Wrong Answer
// class Solution {
//  public:
//   int minScoreTriangulation(std::vector<int>& A) {
//     int n = A.size(), ans = 0;
//     std::vector<std::vector<int>> C(n, std::vector<int>(n));
//     for (int i = 0; i < n-2; ++i) {
//       for (int j = 2; j < n; ++j) {
//         int t = INT_MAX;
//         for (int k = i+1; k < j; ++k)
//           t = std::min(
//               t, C[i][k] + C[k][j] + A[i]*A[j]*A[k]);
//         if (t != INT_MAX)
//           C[i][j] = t;
//       }
//     }
//     return C[0][n-1];
//   }
// };

// 4ms 98.14% 8.8MB 100.00%
// dynamic prog
// O(N^3) O(N)
class Solution {
 public:
  int minScoreTriangulation(std::vector<int>& A) {
    int n = A.size(), ans = 0;
    // C[i][j]: max prod sum [i..j]
    std::vector<std::vector<int>> C(n, std::vector<int>(n));
    for (int cnt = 3; cnt <= n; ++cnt) {
      for (int i = 0; i + cnt - 1 < n; ++i) {
        int j = i + cnt - 1;
        int t = INT_MAX;
        for (int k = i+1; k < j; ++k)
          t = std::min(
              t, C[i][k] + C[k][j] + A[i]*A[j]*A[k]);
        if (t != INT_MAX)
          C[i][j] = t;
      }
    }
    return C[0][n-1];
  }
};

int main() {
  return 0;
}
