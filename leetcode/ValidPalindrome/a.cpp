/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 4ms 99.15% 9.3MB 97.96%
// brute force
// O(N) O(1)
class Solution {
 public:
  bool isPalindrome(std::string s) {
    int n = s.size(), i = 0, j = n - 1;
    while (i < j) {
      while (i < j && !std::isalnum(s[i]))
        ++i;
      while (i < j && !std::isalnum(s[j]))
        --j;
      int a = std::tolower(s[i]), b = std::tolower(s[j]);
      if (a != b)
        return false;
      ++i, --j;
    }
    return true;
  }
};

int main() {
  return 0;
}
