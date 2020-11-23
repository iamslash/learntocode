/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/114/others/823/

#include <cstdio>
#include <vector>
#include <string>
#include <stack>

class Solution {
 public:
  int evalRPN(std::vector<std::string>& v) {
    std::stack<int> st;
    int a, b;
    for (const auto& s : v) {
      if (s == "+") {
        b = st.top(); st.pop();
        a = st.top(); st.pop();
        st.push(a + b);
      } else if (s == "-") {
        b = st.top(); st.pop();
        a = st.top(); st.pop();
        st.push(a - b);
      } else if (s == "*") {
        b = st.top(); st.pop();
        a = st.top(); st.pop();
        st.push(a * b);
      } else if (s == "/") {
        b = st.top(); st.pop();
        a = st.top(); st.pop();
        st.push(a / b);
      } else {
        st.push(std::stoi(s));
      }
    }
    return st.top();
  }
};

int main() {
  // std::vector<std::string> v = {"2", "1", "+", "3", "*"};
  // std::vector<std::string> v = {"4", "13", "5", "/", "+"};
  std::vector<std::string> v = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  
  Solution s;
  printf("%d\n", s.evalRPN(v));  
  return 0;
}
