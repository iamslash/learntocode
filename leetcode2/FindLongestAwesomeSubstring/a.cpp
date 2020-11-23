/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//      i
//   s: 3 2 4 2 4 1 5
//      j
//  bm: 0 0 0 0 0 0 0 1 0 0
// ans: 0

using namespace std;

// 96ms 62.54% 9.9MB 72.23%
// too dificult
class Solution {
 public:
  int longestAwesome(string s) {
    int n = s.size();
    vector<int> C(1024, n);
    int ans = 0, bm = 0;
    C[0] = -1;
    for (int i = 0; i < n; ++i) {
      bm ^= 1 << (s[i] - '0');
      ans = max(ans, i - C[bm]);
      for (int j = 0; j <= 9; ++j) {
        ans = max(ans, i - C[bm ^ (1 << j)]);
      }
      C[bm] = min(C[bm], i);
    }
    return ans;
  }
};
