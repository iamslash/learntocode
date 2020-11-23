/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <climits>

// 4ms 84.02%
// brute force
// O(N) O(1)
class Solution {
 public:
  int myAtoi(std::string s) {
    int i = 0, n = s.size(), neg = 0, ans = 0;
    // skip white spaces
    while (s[i] == ' ')
      ++i;
    // check sign
    if (s[i] == '+' || s[i] == '-') {
      if (s[i++] == '-')
        neg = 1;
    }
    // printf("%d\n", neg);
    // convert
    while (i < n) {
      if (!std::isdigit(s[i]))
        break;
      int d = s[i] - '0';
      if (neg) {
        // overflow : ans * 10 - d <= INT_MIN
        //            ans < (INT_MIN + d) / 10
        if (ans < (INT_MIN + d) / 10)
          return INT_MIN;
        ans = ans * 10 - d;
      } else {
        // overflow : ans * 10 + d >= INT_MAX
        //            ans > (INT_MAX - d) / 10
        if (ans > (INT_MAX - d) / 10)
          return INT_MAX;
        ans = ans * 10 + d;
      }
      ++i;
    }
    return ans;
  }
};

int main() {

  // std::string s = "9393249432983249824392390";
  std::string s = "2147483646";

  Solution sln;
  printf("%d\n", sln.myAtoi(s));
  
  return 0;
}
