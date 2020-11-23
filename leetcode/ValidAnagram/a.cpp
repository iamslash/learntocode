// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/

#include <cstdio>
#include <string>

class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size())
      return false;
    int as[26] = {0, };
    int at[26] = {0, };
    for (char c : s) {
      as[c - 'a']++;
    }
    for (char c : t) {
      at[c - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      if (as[i] != at[i])
        return false;
    }
    return true;
  }
};

int main() {
  return 0;
}
