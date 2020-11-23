/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <stack>

// 16ms 56.09% 8.2MB 100.00%
// stack
// O(N) (N)
class Solution {
 private:
  int parseNum(const std::string& s, int& i) {
    int64_t num = 0;
    while (i < s.size() && isdigit(s[i]))
      num = 10 * num + s[i++] - '0';
    return num;
  }
 public:  
  int calculate(std::string s) {
    std::stack<int> numStack, opStack;
    int ans = 0, sign = 1;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (isdigit(c)) {
        int num = parseNum(s, i);
        ans += sign * num;
        i--;
      } else if (c == '+') {
        sign = 1;
      } else if (c == '-') {
        sign = -1;
      } else if (c == '(') {
        numStack.push(ans);
        opStack.push(sign);
        ans = 0;
        sign = 1;
      } else if (c == ')') {
        ans = ans * opStack.top();
        opStack.pop();
        ans += numStack.top();
        numStack.pop();
      }
      //printf("i: %d, ans: %d, sign: %d\n", i, ans, sign);
    }
    return ans;
  }
};

//             i
//        s: "2-1 + 2"
//      ans: 2
//     sign:-1
// numStack:
//  opStack:
int main() {
  Solution sln;
  printf("%d\n", sln.calculate("2-1 + 2"));
  
  return 0;
}
