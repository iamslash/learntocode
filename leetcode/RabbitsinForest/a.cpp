/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

// // 8ms 89,95% 9.2MB 77.78%
// // Q. what is the range of A.size() ? [0..1000]
// // Q. What is the range of A[i] ? [0, 999]
// // greedy approach
// // O(N) O(N)
// class Solution {
//  public:
//   int numRabbits(std::vector<int>& A) {
//     if (A.empty())
//       return 0;
//     std::unordered_map<int, int> C;
//     int r = 0;
//     for (int a : A) {
//       if (a == 0) {
//         ++r;
//       } else {
//         if (C[a] == 0)
//           r += a + 1;
//         C[a]++;
//         if (C[a] == a+1)
//           C[a] = 0;
//       }
//     }
//     return r;
//   }
// };


// r: 2
// c: 1
//        i
// A: 1 1 2

// 4ms 100.00%
// greedy approach
// O(NlgN) O(1)
class Solution {
 public:
  int numRabbits(std::vector<int>& A) {
    std::sort(A.begin(), A.end());
    int n = A.size();
    int r = 0;
    for (int i = 0; i < n; ++i) {
      int a = A[i];
      int cnt = 1;
      while (i+1 < n && cnt < a+1 && A[i+1] == a) {
        ++i;
        ++cnt;
      }
      r += a+1;
    }
    return r;
  }
};

int main() {
  // std::vector<int> A = {1, 1, 2};
  std::vector<int> A = {10, 10, 10};
  Solution sln;
  printf("%d\n", sln.numRabbits(A));
  
  return 0;
}
