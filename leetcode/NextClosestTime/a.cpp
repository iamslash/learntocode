/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <set>

// 0ms 100.00% 8.3MB 69.93%
// incremental
// O(1) O(1)
class Solution {
 public:
  std::string nextClosestTime(std::string s) {
    int mins[4] = {600, 60, 10, 1};
    int nHH = std::stoi(s.substr(0, 2));
    int nMM = std::stoi(s.substr(3, 2));
    int cur = nHH * 60 + nMM;
    std::string nxt = "0000";
    std::set<char> dic(s.begin(), s.end());
    for (int i = 1, d = 0; i <= 1440 && d < 4; ++i) {
      int min = (cur + i) % 1440;
      // printf("min: %d\n", min);
      for (d = 0; d < 4; ++d) {
        nxt[d] = '0' + min / mins[d];
        // printf("  min:%4d, d:%4d, nxt[d]: %c\n", min, d, nxt[d]);
        if (dic.count(nxt[d]) == 0)
          break;
        min %= mins[d];
      }
    }
    return {nxt[0], nxt[1], ':', nxt[2], nxt[3]};
  }
};

//  d
// 19:34

int main() {
  // std::string s = "19:34";
  std::string s = "23:58";
  Solution sln;
  printf("%s\n", sln.nextClosestTime(s).c_str());
  return 0;
}
