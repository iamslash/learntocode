/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>
#include <vector>

//      i
//   A: 8 8 5 2 6
//        j
// ans: 12

//          i
//   A: 7 2 6 6 9 4 3
//            j
// ans: 8

// // 80ms 16.40% 13.2MB 50.00%
// // O(N) O(1)
// class Solution {
//  public:
//   int maxScoreSightseeingPair(std::vector<int>& A) {
//     int i = 0, j = 1, n = A.size(), ans = 0;
//     for (int j = 1; j < n; ++j) {
//       ans = std::max(ans, A[i] + A[j] + i - j);
//       if (A[j] > A[i] + i - j)
//         i = j;
//     }
//     return ans;
//   }
// };

// 64ms 88.72% 13.1MB 83.10%
// O(N) O(1)
class Solution {
 public:
  int maxScoreSightseeingPair(std::vector<int>& A) {
    int ival = A[0] - 1, rslt = INT_MIN, n = A.size();
    for (int j = 1; j < n; ++j) {
      rslt = std::max(rslt, ival + A[j]);
      ival = std::max(ival, A[j]) - 1;
    }
    return rslt;
  }
};

int main() {

  std::vector<int> A = {8, 1, 5, 2, 6};
  Solution sln;
  printf("%d\n", sln.maxScoreSightseeingPair(A));
  
  return 0;
}
