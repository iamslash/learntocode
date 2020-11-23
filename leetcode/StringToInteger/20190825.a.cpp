/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// "  -42"
// "+-2"

// "-42"

// 4ms 84.02% 8.3MB 94.03%
// O(N) O(1)
class Solution {
 public:
  int myAtoi(std::string s) {
    int i = 0, n = s.size(), ans = 0;
    bool neg = false;
    while (i < n && s[i] == ' ')
      ++i;
    if (s[i] == '+')
      ++i;
    else if (s[i] == '-')
      ++i, neg = true;
    while (i < n && std::isdigit(s[i])) {
      int dgt = s[i] - '0';
      if (neg) {
        // ans * 10 - dgt < INT_MIN
        if (ans < (INT_MIN + dgt) / 10)
          return INT_MIN;
        ans = ans * 10 - dgt;
      } else {
        // ans * 10 + dgt > INT_MAX
        if (ans > (INT_MAX - dgt) / 10)
          return INT_MAX;
        ans = ans * 10 + dgt;
      }
      ++i;
    }
    return ans;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.myAtoi("42"));  
  
  return 0;
}
