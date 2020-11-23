/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

// mincnt: 0
// maxcnt: 1
//   i
// (*)
// 4ms 100.00% 8.5MB 76.39%
// O(N) O(1)
class Solution {
 public:
  bool checkValidString(std::string s) {
    int maxcnt = 0, mincnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c == '(') {
        maxcnt++;
        mincnt++;
      } else if (c == ')') {
        maxcnt--;
        mincnt = std::max(0, mincnt-1);
      } else {
        maxcnt++;
        mincnt = std::max(0, mincnt-1);       
      }
      if (maxcnt < 0)
        return false;
    }
    return mincnt == 0;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "True" : "False");
}

int main() {
  Solution sln;
  printb(sln.checkValidString("(*)"));
  return 0;
}
