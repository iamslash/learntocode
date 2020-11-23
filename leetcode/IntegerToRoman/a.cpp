/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/integer-to-roman/description/

#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  std::string intToRoman(int n) {
    std::vector<std::string> S = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    std::vector<int> V = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string r;

    for (int i = 0; i < V.size(); ++i) {
      while (n >= V[i]) {
        n -= V[i];
        r += S[i];
      }
    }
    
    return r;
  }
};

int main() {
  int n = 1994;
  
  Solution s;
  printf("%s\n", s.intToRoman(n).c_str());
  return 0;
}
