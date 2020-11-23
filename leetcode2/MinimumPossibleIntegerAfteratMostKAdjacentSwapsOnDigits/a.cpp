/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

// Time Limit Exceed
// DFS
// O(NlgN) O(N)
class Solution {
 public:
  string minInteger(string s, int k) {
    // base
    if (k <= 0)
      return s;
    int n = s.size();
    if (k >= n*(n+1)/2) {
      sort(s.begin(), s.end());
      return s;
    }
    // recursion
    for (int i = 0; i < 10; i++) {
      int idx = s.find(to_string(i));
      if (idx >= 0 && idx <= k) {
        return s[idx] + minInteger(s.substr(0, idx) +
                                   s.substr(idx+1), k-idx);
      }
    }
    return s;
  }
};
