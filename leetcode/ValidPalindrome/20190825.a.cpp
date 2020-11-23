/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// abc
// abcd

// 4ms 99.15% 9.5MB 36.74%
// O(N) O(1)
class Solution {
 public:
  bool isPalindrome(std::string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (!std::isalnum(s[i])) {
        ++i;
        continue;
      }
      if (!std::isalnum(s[j])) {
        --j;
        continue;
      }
      char a = std::tolower(s[i]);
      char b = std::tolower(s[j]);
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
