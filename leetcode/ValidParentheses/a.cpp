/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

//   i
// s: ( ) [ { } ]
//    c
//      j

// 0ms 100.00% 6.2MB 96.30%
// stack
// O(N) O(1)
class Solution {
public:
  bool isValid(string s) {
    int i = -1, j = 0, n = s.size();
    while (j < n) {
      char c = s[j++];
      if (c == '(' || c == '{' || c == '[' ) {
        s[++i] = c;
      } else if (i >= 0 && c == ')' && s[i] == '(') {
        i--;
      } else if (i >= 0 && c == '}' && s[i] == '{') {
        i--;
      } else if (i >= 0 && c == ']' && s[i] == '[') {
        i--;
      } else {
        return false;
      }
    }
    return i == -1;
  }
};

int main() {
  return 0;
}
