/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <algorithm>

// Similar with
// https://github.com/iamslash/learntocode/tree/master/leetcode2/PalindromePartitioningIII

using namespace std;

// 6 5 4 3 2 1

// // 460ms 11.57%
// // dynamic programming recursive way
// // O(N^2) O(N^2)
// class Solution {
//  private:
//   int64_t dfs(vector<vector<int64_t>>& C, vector<int>& J, int d, int i) {
//     // base
//     int n = J.size();
//     if (d <= 0) {
//       return INT_MAX;
//     }
//     if (d == 1) {
//       return *max_element(J.begin()+i, J.end());
//     }
//     // memo
//     int64_t& r = C[d][i];
//     if (r >= 0)
//       return r;
//     // recursion
//     r = INT_MAX;
//     int maxJ = 0;
//     for (int j = i; j + d - 1 < n; ++j) {
//       maxJ = max(maxJ, J[j]);
//       r = min(r, maxJ + dfs(C, J, d-1, j+1));
//     }
//     return r;
//   }
//  public:
//   int minDifficulty(vector<int>& J, int d) {
//     // edge case
//     int n = J.size();
//     if (n < d)
//       return -1;
//     vector<vector<int64_t>> C(d+1, vector<int64_t>(n, -1));
//     int64_t ans = dfs(C, J, d, 0);
//     if (ans >= INT_MAX)
//       return -1;
//     return int(ans);
//   }
// };

// 44ms 78.93% 7.5MB 72.34%
// dynamic programming iterative way
// O(DN^2) O(N)
class Solution {
 public:
  int minDifficulty(vector<int>& J, int D) {
    int n = J.size();
    if (n < D)
      return -1;
    vector<int> C(n+1, 300000);
    C[n] = 0;
    for (int d = 0; d < D; ++d) {
      for (int i = 0; i < n-d; ++i) {
        int maxJ = 0;
        C[i] = 300000;
        for (int j = i; j < n-d; ++j) {
          maxJ = max(maxJ, J[j]);
          C[i] = min(C[i], maxJ + C[j+1]);
        }
      }
    }
    return C[0];
  }
};
