/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//   C[i]: minimum count of subarray which ends with i index.
//   ans = min(ans, C[r-l-1] + C[r])
//
//   t: 3
//              l
//   A: 3 2 2 4 3
//              r
// sum: 3
//   C: 1 1 1 1 1
// ans: 0
// 

//   t: 6
//            l
//   A: 4 3 2 6 2 3 4
//            r
// sum: 6
//   C: M M M 1
// ans: M

// 236ms 93.17% 74.4MB 60.00%
// dynamic programming
// O(N) O(N)
class Solution {
 public:
  int minSumOfLengths(vector<int>& A, int t) {
    int n = A.size(), l = 0, r = 0, ans = INT_MAX, sum = 0;
    vector<int> C(n, INT_MAX);
    for (r = 0; r < n; ++r) {
      sum += A[r];
      // forward l
      while (sum > t) {
        sum -= A[l++];
      }
      if (sum == t) {
        C[r] = r - l + 1;
        if (l > 0 && C[l-1] != INT_MAX)
          ans = min(ans, C[l-1] + C[r]);
      }
      if (r > 0)
        C[r] = min(C[r], C[r-1]);
    }
    if (ans == INT_MAX)
      return -1;
    return ans;
  }
};
