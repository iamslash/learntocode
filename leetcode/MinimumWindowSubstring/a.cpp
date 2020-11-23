/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/838/

#include <cstdio>
#include <string>
#include <vector>
#include <limits>
#include <unordered_set>

// c 1
// 0    5    0
// ADOBECODEBANC
//           l
//              r
class Solution {
 public:
  std::string minWindow(const std::string& s, const std::string& t) {
    std::vector<int> v(128, 0);
    for (char c : t)
      v[c]++;
    int cnt = t.size();
    int l = 0, r = 0;
    int ridx = -1, rlen = std::numeric_limits<int>::max();
    while (r < s.size()) {
      if (v[s[r]]-- > 0)
        cnt--;
      ++r;
      printf("l:%2d r:%2d c:%2d\n", l, r, cnt);
      while (cnt == 0) {
        if (r - l < rlen) {
          ridx = l;
          rlen = r - l;
        }
        if (v[s[l]]++ == 0)
          cnt++;
        ++l;
        printf("  l:%2d r:%2d c:%2d\n", l, r, cnt);
      }
    }
    return ridx < 0 ? "" : s.substr(ridx, rlen);
  }
};

int main() {
  Solution s;
  printf("%s\n", s.minWindow("ADOBECODEBANC", "ABC").c_str());
  // printf("%s\n", s.minWindow("a", "ab").c_str());
  // printf("%s\n", s.minWindow("a", "aa").c_str());
  return 0;
}
