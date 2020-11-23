// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/817/

#include <cstdio>
#include <string>
#include <cmath>

class Solution {
 public:
  int titleToNumber(std::string s) {
    int r = 0;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      int  d = s.size() - i - 1;
      r += (c - 'A' + 1) * pow(26, d);
    }
    return r;
  }
};

int main() {
  // std::string a = "AB";
  std::string a = "ZY";
  
  Solution s;
  printf("%d\n", s.titleToNumber(a));
}
