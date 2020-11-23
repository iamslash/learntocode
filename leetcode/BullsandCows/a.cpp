/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 1807
// 7810
// V : 0 0 0 0 0 0 0 0 0 0
// 4ms 97.45%
class Solution {
 public:
  std::string getHint(std::string s, std::string g) {
    int nb = 0, nc = 0, n = s.size();
    std::vector<int> V(10);
    for (int i = 0; i < n; ++i) {
      if (s[i] == g[i]) {
        nb++;
      } else {
        if (V[s[i]-'0']++ < 0)
          nc++;
        if (V[g[i]-'0']-- > 0)
          nc++;
      }
    }
    return std::to_string(nb) + "A" +
        std::to_string(nc) + "B";
        
  }  
};

int main() {

  Solution sln;
  printf("%s\n", sln.getHint("1807", "7810").c_str());
  printf("%s\n", sln.getHint("1123", "0111").c_str());
  printf("%s\n", sln.getHint("1122", "1222").c_str());
 
  return 0;
}
