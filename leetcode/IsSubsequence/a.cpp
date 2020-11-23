/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
// a x c
// a h x g d b x c
// 72ms 34.44%
class Solution {
 public:
  bool isSubsequence(std::string s, std::string t) {
    int i = 0, j = 0;
    for (; i < s.size() && j < t.size(); ++j) {
      if (s[i] == t[j])
        i++;
      if (i == s.size())
        return true;
    }
    return i == s.size();
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  Solution sln;
  printb(sln.isSubsequence("abc", "ahbgdc"));
  printb(sln.isSubsequence("axc", "ahbgdc"));
  
  return 0;
}
