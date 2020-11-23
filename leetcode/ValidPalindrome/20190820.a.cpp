// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>

class Solution {
 public:
  bool isPalindrome(std::string s) {
    if (s.size() == 0)
      return true;
    int i = 0, j = 0;
    // remove non-alphanumeric characters
    for (i = 0, j = 0; i < s.size(); ++i) {
      if (isalnum(s[i]))
        s[j++] = s[i];
    }
    for (i = 0; i < --j; ++i) {
      if (tolower(s[i]) != tolower(s[j]))
        return false;
    }
    return true;
  }
};

int main() {
  Solution s;
  // printf("%s\n", s.isPalindrome("A man, a plan, a canal: Panama") ?
  //        "true" : "false");
  printf("%s\n", s.isPalindrome("a.") ?
         "true" : "false");
  return 0;
}
