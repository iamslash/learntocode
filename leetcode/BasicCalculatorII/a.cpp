// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/836/

#include <cstdio>
#include <string>
#include <sstream>

//             l
// 0 + 3 + 2 * 2 + 0
//
class Solution {
 public:
  int calculate(std::string s) {
    std::istringstream iss("+"+s+"+");
    int r = 0;     // total
    int last = 0;  // last term
    char opr = 0;  // operator
    int opd = 0;   // operand
    while (iss >> opr) {
      iss >> opd;
      printf("opr: %c, opd: %d\n", opr, opd);
      if (opr == '+' || opr == '-') {
        r += last;
        last = (opr == '+' ? opd : -opd);
      } else if (opr == '*') {
        last *= opd;
      } else if (opr == '/') {
        last /= opd;
      }
    }
    return r;
  }
};

int main() {
  std::string a = "+3 + 2   * 2+";

  std::istringstream iss(a);
  char opr = 0;
  int  opd = 0;
  for (int i = 0; i < 5; ++i) {
    int a = (iss >> opr);
    int b = iss >> opd;
    printf("opr: %c, opd: %d, a: %d, b: %d\n", opr, opd, a, b);
  }
  return 0;
}
