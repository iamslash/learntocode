/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <string>

// 72ms 87.61% 13.4MB 100.00%
// sliding window
// O(N) O(N)
class Solution {
 public:
  int maxFreq(std::string s, int maxL, int minS, int maxS) {
    int i = 0, j = 0, uniq = 0, ans = 0;
    int cnt[26] = {};
    std::unordered_map<std::string, int> cnts;
    while (j < s.size()) {
      if (++cnt[s[j++] - 'a'] == 1)
        ++uniq;
      while (uniq > maxL || j - i > minS) {
        if (--cnt[s[i++] - 'a'] == 0)
          --uniq;
      }
      if (j - i == minS)
        ans = std::max(ans, ++cnts[s.substr(i, minS)]);
    }
    return ans;
  }
};
