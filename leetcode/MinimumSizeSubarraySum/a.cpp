/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

//                i
//   V: 2 3 1 2 4 3
//                  j
// sum: 3

//   s: 3
//      i
//   V: 1 1
//          j
// sum: 2

// // 8ms 99.08% 9.9MB 71.73%
// // sliding window
// // O(N) O(1)
// class Solution {
//  public:
//   int minSubArrayLen(int s, std::vector<int>& V) {
//     if (V.empty())
//       return 0;
//     int i = 0, j = 0, n = V.size();
//     int minlen = INT_MAX;
//     int sum = 0;
//     while (j < n) {
//       sum += V[j++];
//       while (sum >= s) {
//         minlen = std::min(minlen, j - i);
//         sum -= V[i++];
//       }
//       // printf("i: %d, j: %d, sum: %d, min: %d\n", i, j, sum, minlen);
//     }
//     return minlen == INT_MAX ? 0 : minlen;
//   }
// };

//                
//   V: 2 3 1 2 4 3
//            i
//  ps: 2 5 6 8 1215
//      j
// sum: 5
//

// 12ms 93.81% 10.2MB 6.98%
// binary search
// O(NlgN) O(N)
class Solution {
 public:
  int minSubArrayLen(int s, std::vector<int>& V) {
    if (V.empty())
      return 0;
    int n = V.size(), minlen = INT_MAX;
    std::vector<int> ps(n, 0);
    std::partial_sum(V.begin(), V.end(), ps.begin());
    for (int i = n-1; i >= 0 && ps[i] >= s; --i) {
      int j = std::upper_bound(ps.begin(), ps.end(), ps[i] - s) - ps.begin();
      minlen = std::min(minlen, i - j + 1);
    }
    return minlen == INT_MAX ? 0 : minlen;
  }
};

int main() {
  // std::vector<int> V = {2, 3, 1, 2, 4, 3};
  // std::vector<int> V = {1, 2, 3, 4, 5};
  std::vector<int> V = {1, 1};
  Solution sln;
  printf("%d\n", sln.minSubArrayLen(3, V));
  return 0;
}
