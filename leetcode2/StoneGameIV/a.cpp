/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// // 352ms 31.97% 35MB 100.00%
// // dynamic programming recursive way
// // O(N) O(N)
// class Solution {
//  private:
//   int dfs(vector<vector<int>>& C, int n, int ord) {
//     // printf("%d\n", n);
//     // base
//     if (n <= 0)
//       return false;
//     // memo
//     int& r = C[n][ord];
//     if (r >= 0)
//       return r;
//     // recursion
//     for (int i = 1; i*i <= n; ++i) {
//       if (!dfs(C, n-i*i, ord^0))
//         return r = true;
//     }
//     return r = false;    
//   }
//  public:
//   bool winnerSquareGame(int n) {
//     vector<vector<int>> C(n+1, vector<int>(2, -1));
//     return dfs(C, n, 0);
//   }
// };

// 196ms 58.70% 64.MB 100.00%
// dynamic programming iterative way
// O(N^2) O(N)
class Solution {
 public:
  bool winnerSquareGame(int n) {
    vector<bool> C(n+1, false);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j*j <= i; ++j) {
        if (!C[i - j*j]) {
          C[i] = true;
          break;
        }
      }
    }
    return C[n];
  }
};

int main() {
  Solution sln;
  sln.winnerSquareGame(99);
  return 0;
}
