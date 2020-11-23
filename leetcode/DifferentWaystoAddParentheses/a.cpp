/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <cctype>

class Solution {
 public:
  std::vector<int> diffWaysToCompute(std::string s) {
    std::vector<int> rslt;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (std::ispunct(c)) {
        for (int a : diffWaysToCompute(s.substr(0, i))) {
          for (int b : diffWaysToCompute(s.substr(i+1))) {
            int n = 0;
            if (c == '+')
              n = a + b;
            else if (c == '-')
              n = a - b;
            else
              n = a * b;
            rslt.push_back(n);
          }
        }
      }
    }
    return rslt.size() > 0 ? rslt : std::vector<int>{std::stoi(s)} ;
  }
};

int main() {
  std::string s0 = "2-1-1";
  std::string s1 = "2*3-4*5";
  Solution sln;
  auto rslt = sln.diffWaysToCompute(s1);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");
  
  return 0;
}
