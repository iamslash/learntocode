/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 40ms 68.21%
class Solution {  
 private:
  std::string m_s;
  std::string m_p;
  std::vector<std::vector<int>> m_C;
  bool _isMatch(int si, int pi) {
    // printf("%d %d\n", si, pi);

    // memoization
    int & r = m_C[si][pi];
    if (r != -1)
      return r;

    // recursion
    if (si == m_s.size() && pi == m_p.size()) {
      return r = true;
    } else if (si < m_s.size() && pi < m_p.size() &&
               (m_p[pi] == '?' || m_p[pi] == m_s[si])) {
      return r = _isMatch(si+1, pi+1);
    } else if (m_p[pi] == '*') {
      if (_isMatch(si, pi+1) ||
          (si < m_s.size() && _isMatch(si+1, pi)))
        return r = true;
    }
    return r = false;
  }
 public:
  bool isMatch(std::string s, std::string p) {
    m_C = std::vector<std::vector<int>>(s.size()+1, std::vector<int>(p.size()+1, -1));
    m_s = s;
    m_p = p;
    return _isMatch(0, 0);
  }
};

int main() {
  std::string s0 = "aa";
  std::string p0 = "a";
  std::string s1 = "aa";
  std::string p1 = "*";
  std::string s2 = "cb";
  std::string p2 = "?a";
  std::string s3 = "adceb";
  std::string p3 = "a*b";
  std::string s4 = "acdcb";
  std::string p4 = "a*c?b";

  Solution sln;
  printf("%s\n", sln.isMatch(s0, p0) ? "true" : "false");
  printf("%s\n", sln.isMatch(s1, p1) ? "true" : "false");
  printf("%s\n", sln.isMatch(s2, p2) ? "true" : "false");
  printf("%s\n", sln.isMatch(s3, p3) ? "true" : "false");
  printf("%s\n", sln.isMatch(s4, p4) ? "true" : "false");
  
  return 0;
}
