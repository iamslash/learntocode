/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;

// // 80ms 35.48% 25.7MB 27.98%
// // dynamic programming recursive way
// // O(N) O(N)
// #define MOD 1000000007
// class Solution {
//  private:
//   int dfs(vector<vector<int>>& C, int n, int u) {
//     // base
//     if (n == 0)
//       return 1;    
//     // memo
//     int& r = C[n][u];
//     if (r >= 0)
//       return r;
//     // recursion
//     r = 0;
//     for (int v = 0; v < 5; v++) {
//       if ((u == 0 && v != 1) ||
//           (u == 1 && (v != 0 && v != 2)) ||
//           (u == 2 && v == 2) ||
//           (u == 3 && (v != 2 && v != 4)) ||
//           (u == 4 && v != 0)){
//         continue;
//       }
//       r = (r + dfs(C, n-1, v)) % MOD;
//     }
//     return r;
//   }
//  public:
//   int countVowelPermutation(int n) {
//     // a e i o u
//     // 0 1 2 3 4
//     vector<vector<int>> C(n, vector<int>(5, -1));
//     int ans = 0;
//     for (int u = 0; u < 5; u++)
//       ans = (ans + dfs(C, n-1, u)) % MOD;
//     return ans;
//   }
// };

// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.
//===========
// e -> a
// {a, i} -> e
// {a, e, o, u} -> i
// {i, u} -> o
// {a} -> u
//===========
// a -> {e, i, u}
// e -> {a, i}
// i -> {e, o}
// o -> {i}
// u -> {i, o}

// 68ms 49.08% 27.1MB 27.34%
// dynamic programming iterative way
// O(N) O(N)
#define MOD 1000000007;
class Solution {
 public:
  int countVowelPermutation(int n) {
    vector<vector<int64_t>> C(n+1, vector<int64_t>(5, 0));
    for (int u = 0; u < 5; ++u)
      C[1][u] = 1;
    for (int i = 2; i <= n; ++i) {
      C[i][0] = (C[i-1][1] + C[i-1][2] + C[i-1][4]) % MOD;
      C[i][1] = (C[i-1][0] + C[i-1][2]) % MOD;
      C[i][2] = (C[i-1][1] + C[i-1][3]) % MOD;
      C[i][3] = (C[i-1][2]) % MOD;
      C[i][4] = (C[i-1][2] + C[i-1][3]) % MOD;      
    }
    int64_t ans = 0;
    for (int u = 0; u < 5; ++u)
      ans = (ans + C[n][u]) % MOD;
    return ans;
  }
};
