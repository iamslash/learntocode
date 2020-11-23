/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 12ms 59.32% 11.6MB 82.76%
// O(NlgN) O(N)
class Solution {
 public:
  std::string findContestMatch(int n) {
    std::vector<std::string> r(n);
    for (int i = 0; i < n; ++i)
      r[i] = std::to_string(i+1);
    while (n > 1) {
      for (int i = 0; i < n/2; ++i) {
        r[i] = "(" + r[i] + "," + r[n-1-i] + ")";
      }
      n /= 2;
    }
    return r[0];
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.findContestMatch(8).c_str());
  
  return 0;
}
