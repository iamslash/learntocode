/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <unordered_set>

// 4ms 74.32%
class Solution {
 private:
  std::unordered_set<std::string> m_rslt; // result
  // cntl : count of left parentheses
  // cntr : count of right parentheses
  // cntp : count of parentheses paris
  // comb : combination of characters
  void _solve(std::string s, int i, int cntl, int cntr, int cntp,
              std::string comb) {
    for (int j = 0; j < i; ++j)
      printf(" ");
    printf("i: %d, cntl: %d, cntr: %d, cntp: %d, comb: %s\n",
           i, cntl, cntr, cntp, comb.c_str());
    
    // base condition
    if (i == s.size()) {
      if (cntl == 0 && cntr == 0 && cntp == 0)
        m_rslt.insert(comb);
      return;
    }

    // recursion
    if (s[i] != '(' && s[i] != ')') {
      _solve(s, i+1, cntl, cntr, cntp, comb+s[i]);
    } else {
      if (s[i] == '(') {
        if (cntl > 0) {
          _solve(s, i+1, cntl-1, cntr, cntp, comb);
        }
        _solve(s, i+1, cntl, cntr, cntp+1, comb+s[i]);        
      } else if (s[i] == ')') {
        if (cntr > 0) {
          _solve(s, i+1, cntl, cntr-1, cntp, comb);
        }
        if (cntp > 0) {
          _solve(s, i+1, cntl, cntr, cntp-1, comb+s[i]);
        }
      }
      
    }
  }
 public:
  std::vector<std::string> removeInvalidParentheses(std::string s) {
    int cntl = 0, cntr = 0, cntp = 0;
    for (char c : s) {
      if (c == '(') {
        ++cntl;
      } else if (c == ')') {
        if (cntl > 0) {
          --cntl;
        } else {
          ++cntr;
        }
      }
    }
    _solve(s, 0, cntl, cntr, cntp, "");
    return std::vector<std::string>(m_rslt.begin(), m_rslt.end());
  }
};

int main() {
  std::string s0 = "()())()";
  std::string s1 = "(a)())()";
  std::string s2 = ")(";
  Solution sln;
  auto rslt = sln.removeInvalidParentheses(s2);
  for (const std::string& a : rslt) {
    printf("%s\n", a.c_str());
  }
  return 0;
}
