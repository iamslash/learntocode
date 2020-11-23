/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <stack>

// // 348ms 10.59% 10.3MB 71.70%
// // brute force
// // O(N^2) O(1)
// class Solution {
//  public:
//   bool isValid(std::string s) {
//     int i = 0;
//     while ((i = s.find("abc")) >= 0) {
//       printf("  %s\n", s.c_str());
//       s.erase(i, 3);
//     }
//     return s.empty();
//   }
// };

// 16ms 91.34% 10.3MB 76.42%
// stack
// O(N) O(N)
class Solution {
 public:
  bool isValid(std::string s) {
    if (s.size() % 3 || (!s.empty() && s[0] != 'a'))
      return false;
    std::stack<char> stck;
    for (char c : s) {
      if (c == 'a' || c == 'b') {
        stck.push(c);
      } else {
        if (stck.empty() || stck.top() != 'b')
          return false;
        stck.pop();
        if (stck.empty() || stck.top() != 'a')
          return false;
        stck.pop();
      }
    }
    return stck.empty();
  }
};


void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  // std::string s = "aabcbc";
  std::string s = "abcabcababcc";

  Solution sln;
  printb(sln.isValid(s));
  
  return 0;
}
