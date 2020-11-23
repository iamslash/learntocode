/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/779/

#include <cstdio>
#include <string>
#include <map>

class Solution {
 public:
  int lengthOfLongestSubstring(std::string s) {
    int r = 0;
    int i = 0, j = 0;
    std::map<char, int> cnts;

    while ( (s.size() > 0) && (j < s.size()) ) {
      if (cnts.find(s[j]) == cnts.end())
        cnts[s[j]] = 0;
      cnts[s[j]]++;
      // check i should be lesser than j
      while ( (i < j) && (cnts[s[j]] > 1) ) {
        cnts[s[i]] = std::max(0, --cnts[s[i]]);
        i++;
      }
      r = std::max(r, j-i+1);
      j++;
    }

    return r;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.lengthOfLongestSubstring("abcabcbb"));
  printf("%d\n", s.lengthOfLongestSubstring("bbbbb"));
  printf("%d\n", s.lengthOfLongestSubstring("pwwkew"));
  return 0;
}
