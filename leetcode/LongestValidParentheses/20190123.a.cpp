/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <stack>

//                  i
//    s : ) ( ) ( ) )
// stck : - 0 5
// rslt : 4
//
// 8ms 97.19%
// O(N) O(N)
class Solution {
 public:
  int longestValidParentheses(std::string s) {
    std::stack<int> stck;
    stck.push(-1);
    int rslt = 0;
    for (int i = 0; i < s.size(); ++i) {
      int t = stck.top();
      if (t != -1 && s[i] == ')' && s[t] == '(') {
        stck.pop();
        rslt = std::max(rslt, i - stck.top());
      } else {
        stck.push(i);
      }
    }
    return rslt;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.longestValidParentheses(")())()())"));
  
  return 0;
}
