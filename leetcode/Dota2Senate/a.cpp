/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <queue>

// 12ms 100.00% 10.6MB 100.00%
// O(N) O(N)
class Solution {
 public:
  std::string predictPartyVictory(std::string s) {
    std::queue<int> qr, qd;
    int n = s.size();
    for (int i = 0; i < n; ++i)
      s[i] == 'R' ? qr.push(i) : qd.push(i);
    while (!qr.empty() && !qd.empty()) {
      int i = qr.front(); qr.pop();
      int j = qd.front(); qd.pop();
      i < j ? qr.push(i+n) : qd.push(j+n);
    }
    return qr.size() > qd.size() ? "Radiant" : "Dire";        
  }
};

int main() {

  Solution sln;
  printf("%s\n", sln.predictPartyVictory("RDD").c_str());
  
  return 0;
}
