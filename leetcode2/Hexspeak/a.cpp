/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// brute force
// O(S) O(1)
class Solution {
 public:
  string toHexspeak(string s) {
    int64_t num = stol(s);
    string ans = "";
    while (num > 0) {
      int d = num % 16;
      char c;
      // printf("%d\n", d);
      if (d > 1 && d < 10)
        return "ERROR";
      else if (d == 0)
        c = 'O';
      else if (d == 1)
        c = 'I';
      else
        c = 'A' + d - 10;
      ans = c + ans;
      num /= 16;
    }
    return ans;
  }
};
