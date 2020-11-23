/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// s: a b a
//    a a a
//      b

// s: a b c a b c
//    a a a a
//      b
//            b
//        c
//              c

// 164ms 30.14%9.4MB 60.00%
// dynamicprogramming
// O(N^3) O(N^2)
class Solution {
 public:
  int strangePrinter(string s) {
    if (s.empty())
      return 0;
    int n = s.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      C[i][i] = 1;
      if (i < n - 1) {
        C[i][i+1] = s[i] == s[i+1] ? 1 : 2;
      }
    }
    for (int len = 2; len < n; ++len) {
      for (int beg = 0; beg + len < n; ++beg) {
        C[beg][beg+len] = len + 1;
        for (int k = 0; k < len; ++k) {
          int tmp = C[beg][beg+k] + C[beg+k+1][beg+len];
          C[beg][beg+len] = min(
              C[beg][beg+len],
              s[beg+k] == s[beg+len] ? tmp-1 : tmp);
        }
      }
    }
    return C[0][n-1];
  }
};
