/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

// 1 22 11 2 1 22 1 22 11 2 11 22
// 1 2 2 1 1 2 1 2 2 1 2 2
// 12ms 18.75%
// O(N) O(N)
class Solution {
 public:
  int magicalString(int n) {
    std::string s = "122";
    int i = 2;
    while (s.size() < n) {
      s += std::string(s[i++] - '0', s.back() ^ 3);
    }
    // printf("%s\n", s.c_str());
    return std::count(s.begin(), s.begin()+n, '1');
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.magicalString(4));
  
  return 0;
}
