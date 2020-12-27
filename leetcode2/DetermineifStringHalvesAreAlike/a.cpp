/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 4ms 66.67% 6.9MB 66.67%
class Solution {
 public:
  bool halvesAreAlike(string s) {
    int a = 0, b = 0, n = s.size(), half = n/2;
    for (int i = 0; i < n; ++i) {
      if (s[i] != 'a' &&
          s[i] != 'e' &&          
          s[i] != 'i' &&          
          s[i] != 'o' &&          
          s[i] != 'u' &&          
          s[i] != 'A' &&          
          s[i] != 'E' &&          
          s[i] != 'I' &&          
          s[i] != 'O' &&          
          s[i] != 'U') {
        continue;
      }        
      if (i < half) {
        a++;
      } else {
        b++;
      }
    }
    return a == b;
  }
};
