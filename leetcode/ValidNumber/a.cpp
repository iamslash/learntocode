/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 4ms 95.77% 8.2MB 72.86%
// O(N) O(1)
class Solution {
 public:
  bool isNumber(std::string s) {
    // st: status
    // fg: number is inputted
    int st = 0, fg = 0;
    // trim left, right
    while (s[0] == ' ')
      s.erase(0, 1);
    while (s[s.size()-1] == ' ')
      s.erase(s.size()-1, 1);
    // DFA
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        fg = 1;
        if (st <= 2)
          st = 2;
        else
          st = (st <= 5) ? 5 : 7;
      } else if (s[i] == '+' || s[i] == '-') {
        if (st == 0 || st == 3)
          st++;
        else
          return false;
      } else if (s[i] == '.') {
        if (st <= 2)
          st = 6;
        else
          return false;
      } else if (s[i] == 'e') {
        if (fg && (st == 2 || st == 6 || st == 7))
          st = 3;
        else
          return false;           
      } else {
        return false;
      }        
    }
    return (st == 2 || st == 5 || (fg && st == 6) || st == 7);
  }
};

int main() {
  return 0;
}
