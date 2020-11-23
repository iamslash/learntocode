/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/794/

#include <cstdio>
#include <vector>
#include <string>

// n: 3
// ((()))
// (()())
// (())()
// ()(())
// ()()()
//
//

class Solution {
 public:
  std::vector<std::string> r;
  void _solve(std::string str, int cnt_left, int cnt_ing) {
    // base condition
    if (cnt_left == 0) {
      for (int i = 0; i < cnt_ing; ++i)
        str += ")";
      r.push_back(str);
      return;
    }

    // recursion
    if (cnt_ing == 0) {
      _solve(str + "(", cnt_left - 1, cnt_ing + 1);
    } else {
      _solve(str + "(", cnt_left - 1, cnt_ing + 1);
      _solve(str + ")", cnt_left, cnt_ing - 1);
    }
  }
  std::vector<std::string> generateParenthesis(int n) {
    _solve("", n, 0);
    return r;
  }
};

int main() {
  Solution s;
  std::vector<std::string> r = s.generateParenthesis(3);
  for (const auto& s : r) {
    printf("%s\n", s.c_str());
  }
  return 0;
}
