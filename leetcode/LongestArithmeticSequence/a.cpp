/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// // 2369ms 27.07% 197.MB 56.48%
// // dynamin prog
// // O(N^2) O(N)
// class Solution {
//  public:
//   int longestArithSeqLength(std::vector<int>& A) {
//     // {difference: {last number: count of difference}}
//     std::unordered_map<
//       int, std::unordered_map<int, int>> C;
//     int ans = 2, n = A.size();
//     for (int i = 0; i < n; ++i) {
//       for (int j = i+1; j < n; ++j) {
//         int d = A[j] - A[i];
//         C[d][j] = C[d].count(i) ? C[d][i] + 1 : 2;
//         ans = std::max(ans, C[d][j]);
//       }
//     }
//     return ans;
//   }
// };

// 28ms 99.49% 39.9MB 83.33%
// dynamic prog
// O(N^2) O(N)
class Solution {
 public:
  int longestArithSeqLength(std::vector<int>& A) {
    int n = A.size(), ans = 0;
    // pos[num]: index of num 
    std::vector<int> pos(10001, -1);
    // C[i][j]: count of diff between A[i] and A[j]
    std::vector<std::vector<int>> C(n, std::vector<int>(n));
    pos[A[0]] = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        int prv = 2 * A[i] - A[j];
        if (prv < 0 || prv > 10000 || pos[prv] == -1)
          continue;
        C[i][j] = C[pos[prv]][i] + 1;
        ans = std::max(ans, C[i][j]);
      }
      pos[A[i]] = i;
    }
    return ans + 2;
  }
};

int main() {
  return 0;
}
