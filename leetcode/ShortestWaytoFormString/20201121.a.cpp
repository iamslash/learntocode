/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// s: abc
//       i
// t: abcbc
//         j
// a: 1

// s: abc
//    i
// t: acdbc
//      j
// a: 3

// O(T) O(1)
class Solution {
 public:
  int shortestWay(string s, string t) {
    int i = 0, j = 0, ans = 0;
    while (j < t.size() && ans <= j) {
      while (s[i] != t[j] && i < s.size())
        ++i;
      if (i == s.size()) {
        i = 0;
        ++ans;
      } else {
        ++i;
        ++j;
      }
    }
    return ans <= j ? ans + 1 : -1;
  }
};

int main() {
  return 0;
}
