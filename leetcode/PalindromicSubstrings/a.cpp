/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>

// 4ms 93.47%
class Solution {
 public:
  int countSubstrings(std::string s) {
    int rslt = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; ++j)
        rslt++;
      for (int j = 0; i-j-1 >= 0 && i+j < n && s[i-1-j] == s[i+j]; ++j)
        rslt++;
    }
    
    return rslt;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.countSubstrings("abc"));
  printf("%d\n", sln.countSubstrings("aaa"));
  
  return 0;
}
