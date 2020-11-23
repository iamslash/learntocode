/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// E 2 3
// 2 X 2
// 1 2 S

// // 16ms 83.32% 9.3MB 39.71%
// // iterative dynamic programming
// // O(N^2) O(N^2)
// #define MOD 1000000007
// class Solution {
//  public:
//   vector<int> pathsWithMaxScore(vector<string>& B) {
//     vector<int> dirs {1, 0, 1, 1};
//     int n = B.size();
//     vector<vector<int>> scoreC(n+1, vector<int>(n+1));
//     vector<vector<int>> pathC(n+1, vector<int>(n+1));
//     B[0][0] = B[n-1][n-1] = '0';
//     pathC[0][0] = 1;
//     for (int y = 1; y <= n; ++y) {
//       for (int x = 1; x <= n; ++x) {
//         if (B[y-1][x-1] == 'X')
//           continue;
//         for (int d = 0; d < 3; ++d) {
//           int py = y - dirs[d];
//           int px = x - dirs[d+1];
//           int pv = scoreC[py][px] + (B[y-1][x-1] - '0');
//           if (scoreC[y][x] <= pv && pathC[py][px] > 0) {
//             if (scoreC[y][x] < pv)              
//               pathC[y][x] = 0;
//             pathC[y][x] = (pathC[y][x] + pathC[py][px]) % MOD;
//             scoreC[y][x] = pv;
//           }
//         }
//       }
//     }
//     int maxPath = pathC[n][n];
//     int maxScore = 0;
//     if (pathC[n][n] > 0) {
//       maxScore = scoreC[n][n];
//     }
//     return {maxScore, maxPath};
//   }
// };

// 4ms 99.63% 7.9MB 79.41%
// iterative dynamic programming
// O(N^2) O(N^2)
#define MOD 1000000007
class Solution {
 public:
  vector<int> pathsWithMaxScore(vector<string>& B) {
    int n = B.size();
    int64_t C[n][n][2];
    memset(C,0,sizeof(C));
    B[0][0]='0';
    for (int y = n-1; y >= 0; y--) {
      for (int x = n-1; x >= 0; x--) {
        if (B[y][x]=='X')
          continue;
        if (y == n-1 || x == n-1) {
          if (y == n-1 && x == n-1){
            C[y][x][0] = 0;
            C[y][x][1] = 1;
          } else if (y == n-1) {
            int64_t k = C[y][x+1][0];
            C[y][x][0] = (int64_t)(B[y][x]-'0') + k;
            C[y][x][1] = C[y][x+1][1] % MOD;
          } else {
            int64_t k = C[y+1][x][0];
            C[y][x][0] = (int64_t)(B[y][x]-'0') + k;
            C[y][x][1] = C[y+1][x][1] % MOD;
          }
          continue;
        }
        int64_t prevMaxCost = max(C[y+1][x][0],
                                  max(C[y][x+1][0],
                                      C[y+1][x+1][0]));
        C[y][x][0] = (int64_t)(B[y][x]-'0') + prevMaxCost;
        C[y][x][1] = (((C[y+1][x][0] == prevMaxCost) ? C[y+1][x][1] : 0) % MOD +
                      ((C[y][x+1][0] == prevMaxCost) ? C[y][x+1][1] : 0) % MOD +
                      ((C[y+1][x+1][0]==prevMaxCost) ? C[y+1][x+1][1]:0) % MOD) % MOD;
      }
    }
    if(C[0][0][1] == 0)
      return{0, 0};
    return {(int)C[0][0][0],(int)C[0][0][1]};
  }
};
