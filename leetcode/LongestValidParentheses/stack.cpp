/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <stack>

//           i
//       0 1 
//    s: ( )
// stck: 0 1

// 8ms 64.25%
// O(N) O(N)
class Solution {
 public:
  int longestValidParentheses(std::string s) {
    if (s.empty())
      return 0;
    int rslt = 0;
    std::stack<int> stck;
    for (int i = 0; i < s.size(); ++i) {
      if (!stck.empty() && s[i] == ')' &&
          s[stck.top()] == '(') {
        stck.pop();
        int t = stck.empty() ? -1 : stck.top();
        rslt = std::max(rslt, i - t);
      } else {
        stck.push(i);
      }
    }
    return rslt;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.longestValidParentheses("()"));
  
  return 0;
}
