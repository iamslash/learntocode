// Copyright (C) 2018 by iamsalsh
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/

#include <cstdio>
#include <string>
#include <cctype>
#include <climits>

class Solution {
 public:
  int myAtoi(std::string str) {
    const char * p = str.c_str();
    bool neg = false;
    int r = 0;
    // skip space
    while (*p && isspace(*p))
      p++;
    // skip +
    if (*p == '+') {
      p++;
    } else if (*p == '-') {
      p++;
      neg = true;
    }
    for (; *p && isdigit(*p); ++p) {
      int d = *p - '0';
      if (neg) {
        if (r < (INT_MIN + d) / 10)
          return INT_MIN;
        r = r * 10 - d;
      } else {
        if (r > (INT_MAX - d) / 10)
          return INT_MAX;
        r = r * 10 + d;
      }
    }
    return r;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.myAtoi("32342"));
  return 0;
}
