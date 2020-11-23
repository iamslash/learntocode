/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 20ms 85.77% 11.8MB 73.91%
// brute force
// O(N) O(1)
class Solution {
 public:
  std::string reverseWords(std::string s) {
    int i = 0, j = 0, n = s.size();
    while (i < n) {
      while (j < n && s[j] != ' ')
        ++j;
      std::reverse(s.begin()+i, s.begin()+j);
      i = j + 1;
      j = i;
    }
    return s;
  }
};

int main() {
  return 0;
}
