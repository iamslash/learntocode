/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//      s: a a a b a a a
// ch2idx: 0 1
//         0 3
//         1
//         2
//         4
//         5
//         6


// 4ms 97.14 10.1MB 100.00%
// O(N) O(N)
class Solution {
 public:
  int maxRepOpt1(std::string s) {
    int n = s.size(), glbmax = 0;
    std::vector<std::vector<int>> ch2ids(26);
    for (int i = 0; i < n; ++i)
      ch2ids[s[i]-'a'].push_back(i);
    for (int i = 0; i < 26; ++i) {
      int locmax = 0, prv = 0, cnt = 1;
      auto& ids = ch2ids[i];
      for (int j = 1; j < ids.size(); ++j) {
        if (ids[j-1] + 1 == ids[j]) {
          ++cnt;
        } else {
          prv = ids[j-1] + 2 == ids[j] ? cnt : 0;
          cnt = 1;
        }
        locmax = std::max(locmax, prv + cnt);
      }
      glbmax = std::max(glbmax, locmax + (ids.size() > locmax ? 1 : 0));
    }
    return glbmax;
  }
};

int main() {
  return 0;
}
