/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

// 
//   
// l: 0, r: 0
//  i       
// XXRXXRLXRR
//  j
// XRRRRXLXXX

// Q. length of S, E ?
// 20ms 11.48% 9.8MB 86.79%
// O(N) O(1)
class Solution {
 public:
  bool canTransform(std::string S, std::string E) {
    int i = 0, j = 0, n = S.size();
    while (i < n && j < n) {
      while (i < n && S[i] == 'X')
        ++i;
      while (j < n && E[j] == 'X')
        ++j;
      if (S[i] != E[j])
        return false;
      if ((S[i] == 'L' && i < j) ||
          (S[i] == 'R' && i > j))
        return false;
      ++i, ++j;
    }
    return true;
  }
};

int main() {

  std::string s = "XXRXXLXXXX";
  std::string e = "XXXXRXXLXX";
  
  Solution sln;
  printf("%s\n", sln.canTransform(s, e) ? "true" : "false");
  
  return 0;
}
