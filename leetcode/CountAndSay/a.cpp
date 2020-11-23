// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/886/

#include <cstdio>
#include <string>


class Solution {
 private:
  std::string _countAndSay(std::string s) {
    std::string r;
    int cnt = 0;  // count of c
    char c = s[0];
    for (int i = 0; i <= s.size(); ++i) {
      if (i != s.size() && s[i] == c) {
        cnt++;
      } else {
        r += '0' + cnt;
        r += c;
        cnt = 1;
        c = s[i];
      }
    }
    return r;
  }

 public:
  std::string countAndSay(int n) {
    std::string r = "1";
    for (int i = 0; i < n-1; ++i) {
      r = _countAndSay(r);
    }
    return r;
  }
};

int main() {
  Solution s;
  printf("%s\n", s.countAndSay(1).c_str());
  printf("%s\n", s.countAndSay(2).c_str());
  printf("%s\n", s.countAndSay(3).c_str());
  printf("%s\n", s.countAndSay(4).c_str());
  printf("%s\n", s.countAndSay(5).c_str());
  return 0;
}
