/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 0ms 100.00% 6.4MB 50.00%
// brute force
// O(N) O(N)
class Solution {
 public:
  string interpret(string cmd) {
    int n = cmd.size(), i = 0;
    string ans;
    while (i < n) {
      if (cmd[i] == '(') {
        if (cmd[i+1] == ')') {
          ans += 'o';
          i += 2;
        } else {
          ans += "al";
          i += 4;
        }
      } else {
        ans += cmd[i];
        i++;
      }
    }
    return ans;
  }
};
