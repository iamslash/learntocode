/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <stack>

// 
// 0ms 100.00%
class Solution {
 public:
  int scoreOfParentheses(std::string s) {
    std::vector<int> rslt(26, 0);
    int i = 0;
    for (char c : s) {
      if (c == '(') {
        rslt[++i] = 0;
      } else {
        rslt[i-1] += std::max(rslt[i] * 2, 1);
        --i;
      }
    }
    return rslt[0];
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.scoreOfParentheses("()"));
  printf("%d\n", sln.scoreOfParentheses("(())"));
  printf("%d\n", sln.scoreOfParentheses("()()"));
  printf("%d\n", sln.scoreOfParentheses("(()(()))"));
  
  return 0;
}
