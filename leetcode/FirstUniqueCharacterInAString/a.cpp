// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/

#include <cstdio>
#include <string>
#include <map>

class Solution {
 public:
  int firstUniqChar(std::string s) {
    int a[26] = {0, };
    for (char c : s) {
      a[c - 'a']++;
    }
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (a[c - 'a'] == 1)
        return i;
    }
    return -1;
  }
};

// <cnt, <idx, alph>>
int main() {
  Solution s;
  printf("%d\n", s.firstUniqChar("leetcode"));
  printf("%d\n", s.firstUniqChar("loveleetcode"));
  return 0;
}
