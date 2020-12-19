/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// ABCDEFGHI
// JKLMNOPQRSTUVWXYZ
//   i
// 001
// iterative dynamic programming
// O(N) O(1)
class Solution {
 public:
  int numDecodings(std::string s) {
    if (s.empty() || s[0] == '0')
      return 0;
    int n1 = 1;
    int n2 = 0;
    for (int i = 1; i < s.size(); ++i) {
      int m1 = 0;
      int m2 = 0;
      char c = s[i];
      if (c >= '1' && c <= '9') {
        m1 = n1 + n2;
      }
      int n = std::stoi(s.substr(i-1, 2));
      if (n >= 10 && n <= 26)
        m2 = n1;
      n1 = m1;
      n2 = m2;
    }
    return n1 + n2;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.numDecodings("12"));
  printf("%d\n", sln.numDecodings("226"));
  printf("%d\n", sln.numDecodings("110"));
  return 0;
}
