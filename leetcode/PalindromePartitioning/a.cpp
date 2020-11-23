// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/palindrome-partitioning/description/

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
 public:
  std::vector<std::vector<std::string>> m_rslt;
  std::vector<std::string> m_comb;
  bool ispalindrome(std::string s) {
    std::string r = s;
    std::reverse(r.begin(), r.end());
    return r == s;
  }
  void solve(std::string s) {
    // base condition
    if (s.empty()) {
      m_rslt.push_back(m_comb);
      return;
    }
    
    // recursion
    for (int i = 0; i < s.size(); ++i) {
      std::string ss = s.substr(0, i+1);
      if (i > 0 && ispalindrome(ss) == false)
        continue;
      m_comb.push_back(ss);
      solve(s.substr(i+1));
      m_comb.pop_back();
    }
  }
  std::vector<std::vector<std::string>> partition(std::string s) {
    if (s.empty())
      return m_rslt;
    solve(s);
    return m_rslt;
  }
};

int main() {
  std::string s = "aab";

  Solution sln;
  auto r = sln.partition(s);

  for (const auto& rr : r) {
    for (const auto& a : rr) {
      printf("%s ", a.c_str());
    }
    printf("\n");
  }
  return 0;
}
