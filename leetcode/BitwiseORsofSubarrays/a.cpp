/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

// // Time Limit Exceeded
// // dynamic programming
// // O(N^2) O(N^2)
// class Solution {
//  public:
//   int subarrayBitwiseORs(std::vector<int>& A) {
//     int n = A.size();
//     std::vector<std::vector<int>> C(
//         n, std::vector<int>(n, -1));
//     std::unordered_set<int> ust;
//     for (int j = 0; j < n; ++j) {
//       for (int i = 0; i + j < n; ++i) {
//         C[i][j] = j == 0 ? A[i+j] : C[i][j-1] | A[i+j];
//         ust.insert(C[i][j]);
//         // printf("(%d, %d) : %d\n", i, j, C[i][j]);
//       }
//     }
//     return ust.size();
//   }
// };

// 384ms 97.07% 109.2MB 91.63%
// dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int subarrayBitwiseORs(std::vector<int>& A) {
    std::vector<int> C;
    int n = A.size();
    for (int i = 0, s = 0, e = 0; i < n;
         ++i, s = e, e = C.size()) {
      C.push_back(A[i]);
      for (int j = s; j < e; ++j) {
        int val = C[j] | A[i];
        if (C.back() != val)
          C.push_back(val);
      }
    }
    return std::unordered_set<int>(C.begin(), C.end()).size();
  }
};

int main() {

  // std::vector<int> A = {1, 1, 2};
  std::vector<int> A = {1, 2, 4};

  Solution sln;
  printf("%d\n", sln.subarrayBitwiseORs(A));
  
  return 0;
}
