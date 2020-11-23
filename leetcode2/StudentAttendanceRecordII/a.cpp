/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// // Time Limit Exceeded
// // dynamic programming
// // O(N) O(N)
// #define MOD 1000000007
// class Solution {
//  private:
//   int64_t ans = 0;
//   int64_t dfs(vector<vector<vector<int64_t>>>& C,
//            int n, int u, int A, int L) {
//     // for (int i = 0; i < u; i++)
//     //   printf(" ");
//     // printf("u: %d, A: %d, L: %d\n", u, A, L);
//     // base
//     if (u == n) {
//       return 1;
//     }
//     // memo
//     int64_t& r = C[u][A][L];
//     if (r >= 0)
//       return r;
//     // add P
//     r = dfs(C, n, u+1, A, 0) % MOD;
//     if (A < 1)
//       r = (r + dfs(C, n, u+1, A+1, 0)) % MOD;
//     if (L < 2)
//       r = (r + dfs(C, n, u+1, A, L+1)) % MOD;
//     return r;
//   }
//  public:
//   int checkRecord(int n) {
//     vector<vector<vector<int64_t>>> C(n+1, vector<vector<int64_t>>(
//         3, vector<int64_t>(3, -1)));
//     return dfs(C, n, 0, 0, 0) % MOD;
//   }
// };

// 196ms 37.70% 6.1MB 80.80%
// dynamic programming
// O(N) O(1)
#define MOD 1000000007
class Solution {
 private:
  int sum(vector<int>& C, int l, int h) {
    int ans = 0;
    for (int i = l; i <= h; ++i) {
      ans = (ans + C[i]) % MOD;
    }
    return ans;
  }
 public:
  int checkRecord(int n) {
    vector<int> C = {1, 1, 0, 1, 0, 0};
    for (int i = 2; i <= n; ++i) {
      C = {sum(C, 0, 2), C[0], C[1], sum(C, 0, 5), C[3], C[4]};
    }
    return sum(C, 0, 5);
  }
};
