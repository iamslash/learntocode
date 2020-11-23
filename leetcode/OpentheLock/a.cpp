/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

// 164ms 65.93% 34.5MB 46.15%
// BFS
// O(N) O(N)
class Solution {
 public:
  std::string getshifted(std::string s, int seg, int dir) {
    int delta = (dir == 0) ? -1: 1;
    s[seg] = ((s[seg] - '0' + delta + 10) % 10) + '0';
    return s;
  }
  int openLock(std::vector<std::string>& deadends, std::string T) {
    std::unordered_set<std::string> D(deadends.begin(), deadends.end());
    if (D.count("0000"))
      return -1;
    if (T == "0000")
      return 0;
    std::unordered_set<std::string> seen;
    std::queue<std::string> q;
    q.push("0000");
    seen.insert("0000");
    int lv = 0;
    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        std::string u = q.front(); q.pop();
        if (u == T)
          return lv;
        // probe neighbors
        for (int j = 0; j < 4; ++j) {
          for (int d = 0; d < 2; ++d) {
            std::string v = getshifted(u, j, d);
            if (seen.count(v) || D.count(u) > 0)
              continue;
            q.push(v);
            seen.insert(v);
          }
        }
      }
      lv++;
    }
    return -1;
  }
};

int main() {
  // std::vector<std::string> D = {"8888"};
  // std::string T = "0009";
  // std::vector<std::string> D = {"0201","0101","0102","1212","2002"};
  // std::string T = "0202";
  // std::vector<std::string> D = {"8887","8889","8878","8898","8788","8988","7888","9888"};
  // std::string T = "8888";
  std::vector<std::string> D = {"0000"};
  std::string T = "8888";
  
  Solution sln;
  printf("%d\n", sln.openLock(D, T));
  // Solution sln;
  // for (auto& s : D) {
  //   for (int i = 0; i < 2; ++i)
  //     printf("%s\n", sln.getshifted(s, 0, i).c_str());
  // }
  return 0;
}
