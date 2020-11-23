/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 4ms 100.00%
// O(N) O(1)
class Solution {
 public:
  std::string toLowerCase(std::string str) {
    char d = 'a' - 'A';
    for (char& c : str) {
      if (c >= 'A' && c <= 'Z') {
        c += d;
      }
    }
    return str;
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.toLowerCase("Hello").c_str());
  
  return 0;
}
