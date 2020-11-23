/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

// i   j
// 2 4 6 8 10
//       k

// 1932ms 5.08% 243.1MB 7.74%
// hash map
// O(N^2) O(N^2)
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size(), ans = 0;
    unordered_map<int64_t, int64_t> cntMaps[n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; j++) {
        int64_t diff = int64_t(A[i]) - A[j];
        if (diff <= INT_MIN || diff >= INT_MAX)
          continue;
        int64_t c1 = cntMaps[i][diff];
        int64_t c2 = cntMaps[j][diff];
        ans += c2;
        cntMaps[i][diff] = c1 + c2 + 1;
      }
    }
    return ans;
  }
};
