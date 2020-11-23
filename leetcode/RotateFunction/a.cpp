/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdint>
#include <algorithm>

//     A: 4 3 2 6
//
// F(0): 0*B0[0] + 1*B0[1] + 2*B0[2] + 3*B0[3]
// F(1): 0*B1[0] + 1*B1[1] + 2*B1[2] + 3*B1[3]
// F(2): 0*B2[0] + 1*B2[1] + 2*B2[2] + 3*B2[3]
// F(3): 0*B3[0] + 1*B3[1] + 2*B3[2] + 3*B3[3]

// // F(0): 0*B0[0] + 1*B0[1]
// // F(1): 0*B1[0] + 1*B1[1]
// // 1152ms 6.56%
// class Solution {
//  private:
//   int adjidx(int i, int r, int n) {
//     return i-r >= 0 ? i-r : n - std::abs(i-r);
//   }
//  public:
//   int maxRotateFunction(std::vector<int>& A) {
//     if (A.empty())
//       return 0;
//     int64_t rslt = std::numeric_limits<int>::min();
//     for (int k = 0; k < A.size(); ++k) {
//       int64_t Fk = 0;
//       for (int i = 0; i < A.size(); ++i) {
//         Fk += i * (int64_t)A[adjidx(i, k, A.size())];
//       }
//       rslt = std::max(rslt, Fk);
//       // printf("k: %d, Fk: %lld, rslt: %lld\n", k, Fk, rslt);
//     }
//     return rslt;
//   }
// };

// [a, b, c, d]
//
// F0 = 0a + 1b + 2c + 3d
// F1 = 3a + 0b + 1c + 2d
// F2 = 2a + 3b + 0c + 1d
// F3 = 1a + 2b + 3c + 0d
//
// sum = a + b + c + d
// F1 - F0 = 3a -  b -  c - d = 4a - sum = n*a - sum
// F2 - F1 = -a + 3b -  c - d = 4b - sum = n*b - sum
// F3 - F2 = -a -  b - 3c - d = 4c - sum = n*c - sum
//
// Fk - Fk-1 = n*Bk[0] - sum
// Fk-1 = Fk + sum - n*Bk[0]
// Fn = F0
//
// 4ms 100.00%
class Solution {
 public:
  int maxRotateFunction(const std::vector<int>& A) {
    int n = A.size();
    int64_t F = 0;
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
      F += A[i] * i;
      sum += A[i];
    }
    int64_t rslt = F;
    for (int i = n - 1; i > 0; --i) {
      // Fn = F0
      // Fn-1 = Fn + sum - n*Bn[0]
      F = F + sum - n * A[i];
      rslt = std::max(rslt, F);                           
    }
    return rslt;
  }
}; 

int main() {
  // std::vector<int> A = {-2147483648, -2147483648};
  std::vector<int> A = {4, 3, 2, 6};

  Solution sln;
  printf("%d\n", sln.maxRotateFunction(A));
  
  return 0;
}
