/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// 4ms 95.66% 7.9MB 94.70%
// iterative dynamic programming
// O(SW) O(S)
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // C[i]: can be segmented from index i
    int n = s.size();
    vector<bool> C(n+1, false);
    C[n] = true;
    for (int i = n-1; i >= 0; --i) {
      for (string& word : wordDict) {
        if (i + word.size() <= n &&
            C[i + word.size()] &&
            !strncmp(&s[i], word.c_str(), word.size())) {
          C[i] = true;
          break;
        }
      }
    }
    return C[0];
  }
};
