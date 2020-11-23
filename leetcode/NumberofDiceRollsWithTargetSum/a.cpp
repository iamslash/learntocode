/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // 20ms 68.52% 13.3MB 100.00%
// // recursive dynamic programming
// // O(N^2) O(N)
// #define MOD 1000000007
// class Solution {
//  private:
//   int dfs(int d, int f, std::vector<std::vector<int>>& C,
//           int i, int tgt) {
//     // base
//     if (i >= d-1) {
//       if (tgt <= f)
//         return 1;
//       return 0;
//     }
//     int& r = C[i][tgt];
//     if (r != -1)
//       return r;

//     // recursion
//     r = 0;
//     for (int j = 1; j <= f; ++j) {
//       if (tgt - j <= 0)
//         break;
//       r = (r % MOD + dfs(d, f, C, i+1, tgt-j) % MOD) % MOD;
//     }

//     return r;
//   }
//  public:
//   int numRollsToTarget(int d, int f, int tgt) {
//     std::vector<std::vector<int>> C(d+1, std::vector<int>(1001, -1));
//     return dfs(d, f, C, 0, tgt);
//   }
// };

// // iterative dynamic programming
// // O(DFT) O(DT)
// #define MOD 1000000007
// class Solution {
//  public:
//   int numRollsToTarget(int d, int f, int tgt) {
//     std::vector<std::vector<int>> C(
//         d+1, std::vector<int>(tgt+1, 0));
//     for (int i = 1; i <= tgt; ++i) {
//       if (i <= f)
//         C[1][i] = 1;
//     }
//     for (int i = 2; i <= d; ++i) {
//       for (int j = 1; j <= tgt; ++j) {
//         for (int k = 1; k <= f; ++k) {
//           if (j - k >= 1)
//             C[i][j] = (C[i][j] + C[i-1][j-k]) % MOD;
//         }
//       }
//     }
//     return C[d][tgt];
//   }
// };

// 4ms 99.13% 9MB 100.00%
// iterative dynamic programming
// O(DFT) O(F)
#define MOD 1000000007
class Solution {
 public:
  int numRollsToTarget(int d, int f, int tgt) {
    if (d * f < tgt)
      return 0;
    std::vector<int> C(d * f + 1);
    C[0] = 1;

    for (int i = 1; i <= d; ++i) {
      std::vector<int> temp(d * f + 1, 0);
      for (int j = i; j <= f * i; ++j)
        for (int k = 1; k <= std::min(j, f); ++k)
          temp[j] = (temp[j] + C[j-k]) % MOD;
      C = temp;
    }
    
    return C[tgt];
  }
};


int main() {
  return 0;
}
