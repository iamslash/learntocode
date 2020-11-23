/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// // Time Limit Exceeded for
// // 1000
// // 1000
// // 
// // dynamic programming
// // O(N^2K) O(NK)
// #define MOD 1000000007
// class Solution {
//  private:
//   int dfs(vector<vector<int>>& C, int n, int k) {
//     // base
//     if (n == 0)
//       return 0;
//     if (k == 0)
//       return 1;                
//     // memo
//     int& r = C[n][k];
//     if (r >= 0)
//       return r;
//     // recursion
//     r = 0;
//     for (int i = 0; i <= min(k, n-1); ++i) {
//       r = (r + dfs(C, n-1, k-i)) % MOD;
//     }
//     return r;
//   }
//  public:
//   int kInversePairs(int n, int k) {
//     vector<vector<int>> C(n+1, vector<int>(k+1, -1));
//     return dfs(C, n, k);
//   }
// };

// // Time Limit Exceeded for
// // 1000
// // 1000
// // 
// // dynamic programming
// // O(N^2K) O(NK)
// #define MOD 1000000007
// class Solution {
//  public:
//   int kInversePairs(int n, int k) {
//     vector<vector<int>> C(n+1, vector<int>(k+1, -1));
//     for (int i = 1; i <= n; ++i) {
//       for (int j = 0; j <= k; ++j) {
//         if (j == 0) {
//           C[i][j] = 1;
//           continue;
//         }
//         for (int p = 0; p <= min(j, i - 1); p++) {
//           C[i][j] = (C[i][j] + C[i-1][j-p]) % MOD;
//         }
//       }
//     }
//     return C[n][k];    
//   }
// };

// 36ms 66.17% 16.4MB 38.81%
// dynamic programming
// O(NK) O(K)
#define MOD 1000000007
class Solution {
 public:
  int kInversePairs(int n, int k) {
    vector<vector<int>> C(n+1, vector<int>(k+1));
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      C[i][0] = 1;
      for (int j = 1; j <= k; ++j) {
        C[i][j] = (C[i][j-1] + C[i-1][j]) % MOD;
        if (j - i >= 0) {
          C[i][j] = (C[i][j] - C[i-1][j-i] + MOD) % MOD;
          // should add MOD for test case 1000, 1000
        }
      }
    }
    return C[n][k];
  }
};
