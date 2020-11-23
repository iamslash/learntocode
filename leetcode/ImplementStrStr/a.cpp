// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/

#include <cstdio>
#include <string>

class Solution {
 public:
  int strStr(std::string haystack, std::string needle) {
    int h = haystack.size();
    int n = needle.size();
    for (int i = 0; i < h - n + 1; ++i) {
      int j = 0;
      for (; j < n && haystack[i+j] == needle[j]; ++j) {;}
      if (j == n)
        return i;
    }
    return -1;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.strStr("hello", "ll"));
  return 0;
}
