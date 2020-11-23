/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

//      A: 1 2 1 2 1 2
// locmax: 1 3 4 6 7 9
// glbmax: 1 3 4

// TIME LIMIT EXCEEDED
// #define MOD 1000000007
// class Solution {
//  public:
//   int kConcatenationMaxSum(std::vector<int>& A, int k) {
//     int locmax = A[0], glbmax = A[0], n = A.size();
//     for (int i = 0; i < k; ++i) {
//       for (int j = 0; j < n; ++j) {
//         int num = (i == 0 && j == 0) ? 0 : A[j];
//         locmax = std::max(num, (locmax + num) % MOD);
//         glbmax = std::max(glbmax, locmax);
//         // printf("%d ", glbmax);
//       }
//     }
//     // printf("\n");
//     return glbmax;
//   }
// };

// 64ms 37.85% 14.2MB 100.00%
// dynamic programming
// O(N) O(1)
#define MOD 1000000007
class Solution {
 public:
  int kConcatenationMaxSum(std::vector<int>& A, int k) {
    int locmax = A[0], glbmax = A[0], n = A.size();
    int64_t allsum = std::accumulate(A.begin(), A.end(), 0);
    for (int i = 1; i < n * std::min(k, 2); ++i) {
      locmax = std::max(A[i%n], locmax + A[i%n]);
      glbmax = std::max(glbmax, locmax);
    }
    return std::max<int64_t>({
        0, glbmax, allsum * k - (allsum * 2 - glbmax)}) % MOD;
  }
};

int main() {

  std::vector<int> A = {1, 2};
  int k = 3;
  Solution sln;
  printf("%d\n", sln.kConcatenationMaxSum(A, k));
  
  return 0;
}
