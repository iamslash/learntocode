/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

// cba
// abcd
//    i
//    e
// cbafg
// abcd
class Solution {
 public:
  std::string customSortString(std::string S, std::string T) {
    std::sort(T.begin(), T.end(),
              [S](const char a, const char b) {
                return S.find(a) < S.find(b);
              });
    return T;
  }
};

int main() {

  Solution sln;
  printf("%s\n", sln.customSortString("cba", "abcd").c_str());  
  return 0;
}
