// Copyright (C) 2018 by iamslash
//https://leetcode.com/problems/restore-ip-addresses/description/

#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> m_r;
  std::vector<std::string> m_c;
  std::string m_s;
  std::string makeipstr() {
    std::string r;
    for (int i = 0; i < m_c.size(); ++i) {
      r += m_c[i];
      if (i < m_c.size()-1)
        r += ".";
    }
    return r;
  }
  void solve(int step, int start) {
    // for (int i = 0; i < step; ++i)
    //   printf("_");
    // printf("%d | ", start);
    // for (const auto& a: m_c)
    //   printf("%s ", a.c_str());
    // printf("\n");
    
    // base condition
    if (start == m_s.size()) {
      if (m_c.size() == 4) {
        m_r.push_back(makeipstr());
      }
      return;
    } else if (start > m_s.size()) {
      return;
    }
    int remain = m_s.size() - start;
    int possible = (4 - m_c.size())* 3;

    // if (start == 3 && m_c.size() > 0 && m_c[0] == "101") {
    //   printf("%d %d\n", start, m_s.size());
    //   printf("%d %d\n", remain, possible);
    // }
    
    if (remain > possible)
      return;

    // recursion
    for (int i = 1; i <= 3; ++i) {
      std::string s = m_s.substr(start, i);
      
      if (s.size() > 1 && s[0] == '0')
          continue;
      int n = std::stoi(s);
      if (n > 255 || (s.size() >= 2 && n == 0))
        continue;
      m_c.push_back(s);
      solve(step+1, start + i);
      m_c.pop_back();
    }
  }
  std::vector<std::string> restoreIpAddresses(std::string s) {
    if (s.size() > 12)
      return m_r;
    m_s = s;
    solve(1, 0);
    return m_r;
  }
};

int main() {
  // std::string s = "25525511135";
  // std::string s = "010010";
  std::string s = "101023";

  Solution sln;
  auto r = sln.restoreIpAddresses(s);

  for (const auto& a : r) {
    printf("%s\n", a.c_str());
  }
  
  return 0;
}
