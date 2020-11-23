/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 4ms 88.89% 6.7MB 11.11%
// brute force
// O(N^3) O(1)
class Solution {
 public:
  int countSubstrings(string s, string t) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = 0; j < t.size(); ++j) {
        int diffCnt = 0;
        for (int k = 0; i + k < s.size() && j + k < t.size(); ++k) {
          if (s[i+k] != t[j+k] && ++diffCnt > 1)
            break;
          ans += diffCnt;
        }                
      }
    }
    return ans;
  }
};
