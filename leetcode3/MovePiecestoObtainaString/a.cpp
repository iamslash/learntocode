/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

//             i
// s: _L__R__R_
// t: L______RR
//             j
//
//    i
// s: L_
// t: _L
//     j
//
//     i
// s: _R
// t: R_
//    j

// 237ms 7.84% 19MB 73.48%
// two pointers
// O(N) O(1)
class Solution {
public:
  bool canChange(string s, string t) {
    int i = 0, j = 0, n = s.size();
    for (i = 0, j = 0; i < n || j < n; ++i, ++j) {
      while (i < n && s[i] == '_') {
        ++i;
      }
      while (j < n && t[j] == '_') {
        ++j;
      }
      if (i == n ||
          j == n ||
          s[i] != t[j] ||
          (s[i] == 'L' && i < j) ||
          (s[i] == 'R' && i > j)) {
        break;
      }
    }
    return i == n && j == n;
  }
};

int main() {
  return 0;
}
