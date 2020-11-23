/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

// // 40ms 99.06% 19.8MB 27.36%
// // O(N) O(1)
// class Solution {
//  public:
//   int maxValueAfterReverse(vector<int>& A) {
//     int total = 0, ans = 0, n = A.size();
//     int min2 = 123456, max2 = -123456;
//     for (int i = 0; i < n - 1; ++i) {
//       int a = A[i], b = A[i+1];
//       total += abs(a - b);
//       ans = max(ans, abs(A[0]-b) - abs(a-b));
//       ans = max(ans, abs(A[n-1]-a) - abs(a-b));
//       min2 = min(min2, max(a, b));
//       max2 = max(max2, min(a, b));
//     }
//     return total + max(ans, (max2-min2)*2);
//   }
// };

// 48ms 96.23% 19.9MB 8.49%
// iterative dynamic programming
// O(N) O(1)
class Solution {
 public:
  int maxValueAfterReverse(vector<int>& A) {
    int ans = 0;
    int n = A.size();
    if (n <= 1)
      return 0;
    for(int i = 0; i < n-1; i++) {
      ans += abs(A[i] - A[i+1]);
    }

    int minEnd = max(A[0], A[1]);
    int maxStart = min(A[0], A[1]);
    for(int i = 1; i < n; i++) {
      minEnd = min(minEnd, max(A[i], A[i-1]));
      maxStart = max(maxStart, min(A[i], A[i-1]));
    }
    int add = 2 * max(0, maxStart - minEnd);

    for(int i = 1; i < n; i++) {
      int c = abs(A[0] - A[i]) - abs(A[i] - A[i-1]);
      add = max(add, c);
      c = abs(A[n-1] - A[i-1]) - abs(A[i] - A[i-1]);
      add = max(add, c);
    }
    return ans + add;
  }
};
