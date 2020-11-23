// Copyright (C) 2016 by iamslash
// https://leetcode.com/problems/reverse-string/

#include <string>
#include <cstdio>
#include <algorithm>

class Solution {
 public:
  std::string reverseString(std::string s) {
    int i = 0;
    int j = s.size() - 1;
    while (i < j) {
      std::swap(s[i++], s[j--]);
    }
    return s;
  }
};

int main() {
  Solution s;
  printf("%s\n", s.reverseString("hello").c_str());
  return 0;
}
