/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <stack>

// (ed(et(oc))el)
// b  b  b  e

// // recursive way
// // 8ms 25.00% 12.2MB 100.00%
// class Solution {
//  public:
//   std::string reverseParentheses(std::string s) {
//     int n = s.size();
//     int beg = 0, end = n-1;
//     for (int i = 0; i < n; ++i) {
//       if (s[i] == '(')
//         beg = i;
//       if (s[i] == ')') {
//         end = i;
//         std::string t = s.substr(beg + 1, end - beg - 1);
//         std::reverse(t.begin(), t.end());
//         return reverseParentheses(
//             s.substr(0, beg) +
//             t +
//             s.substr(end + 1));
//       }
//     }
//     return s;
//   }
// };

// iterative way
// 4ms 62.50% 8.5MB 100.00%
class Solution {
 public:
  std::string reverseParentheses(std::string s) {
    int n = s.size();
    std::stack<int> stck;
    std::string ans;
    
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        stck.push(i);
      } else if (s[i] == ')') {
        int t = stck.top(); stck.pop();
        std::reverse(s.begin() + t + 1, s.begin() + i);
      }
    }
    
    for (char c : s) {
      if (c != '(' && c != ')')
        ans.push_back(c);
    }
    return ans;
  }
};

int main() {
  return 0;
}
