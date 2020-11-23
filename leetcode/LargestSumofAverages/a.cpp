/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

// // 12ms 75.95% 9.3MB 46.63%
// // dynamic programming with 2d cache
// // O(KN) O(KN)
// class Solution {
//  public:
//   double largestSumOfAverages(std::vector<int>& A, int K) {
//     int n = A.size();
//     if (n == 0 || K == 0)
//       return 0.0;
//     std::vector<std::vector<double>> C(
//         K+1, std::vector<double>(n, 0));
//     std::vector<int> ps(n, 0);
//     std::partial_sum(A.begin(), A.end(), ps.begin());
//     for (int k = 1; k <= K; ++k) {
//       for (int i = k-1; i < n; ++i) {
//         if (k == 1) {
//           C[k][i] = (double)ps[i] / (i+1);
//         } else {
//           for (int j = k-2; j < i; ++j) {
//             C[k][i] = std::max(
//                 C[k][i],
//                 C[k-1][j] + (double)(ps[i] - ps[j]) / (i - j));  
//           }
//         }
//       }
//     }

//     for (int y = 0; y <= K; ++y) {
//       for (int x = 0; x < n; ++x) {
//         printf("%2.2lf ", C[y][x]);
//       }
//       printf("\n");
//     }

//     return C[K][n-1];
//   }
// };

// // dynamic programming with 1d cache
// // 12ms 75.95% 8.8MB 85.04%
// class Solution {
//  public:
//   double largestSumOfAverages(std::vector<int>& A, int K) {
//     int n = A.size();
//     std::vector<double> C(n, 0.0);
//     std::vector<double> ps(n+1);
//     std::partial_sum(A.begin(), A.end(), ps.begin()+1);
//     for (int i = 0; i < n; ++i)
//       C[i] = (ps[n] - ps[i]) / (n-i);
//     for (int k = 0; k < K-1; ++k) {
//       for (int i = 0; i < n; ++i) {
//         for (int j = i+1; j < n; ++j) {
//           C[i] = std::max(C[i], C[j] + (ps[j]-ps[i])/(j-i));
//         }
//       }
//     }
//     return C[0];
//   }
// };

// 8ms 96.32% 9.3MB 45.38%
// dynamic programming with recursion
class Solution {
 private:
  std::vector<std::vector<double>> m_C;
  double solve(std::vector<int>& A, int k, int n) {
    // base
    if (n < k)
      return 0;

    // memo
    double& r = m_C[k][n];
    if (r > 0.0)
      return r;

    // recursion
    double sum = 0;
    for (int i = n-1; i > 0; --i) {
      sum += A[i];
      r = std::max(r, solve(A, k-1, i) + sum / (n - i));
    }
    return r;
  }
 public:
  double largestSumOfAverages(std::vector<int>& A, int K) {
    int n = A.size();
    m_C = std::vector<std::vector<double>>(
        K+1, std::vector<double>(n+1, 0.0));
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += A[i];
      m_C[1][i+1] = sum / (i + 1);
    }
    return solve(A, K, n);
  }
};

int main() {
  std::vector<int> V = {9, 1, 2, 3, 9};
  int K = 3;
  Solution sln;
  printf("%lf\n", sln.largestSumOfAverages(V, 3));
  
  return 0;
}
