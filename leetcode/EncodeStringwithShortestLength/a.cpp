/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 112ms 46.19% 29.4MB 57.14%
// O(N^3) O(N)
class Solution {
 private:
  std::vector<std::vector<std::string>> m_C;
  std::string kstring(std::string& s, int i, int j) {
    std::string t = s.substr(i, j - i + 1);
    auto pos = (t+t).find(t, 1);
    if (pos >= t.size())
      return t;
    return std::to_string(t.size()/pos) +
        '[' + m_C[i][i+pos-1] + ']';
  }
 public:
  std::string encode(std::string s) {
    int n = s.size();
    m_C = std::vector<std::vector<std::string>>(
        n, std::vector<std::string>(n, ""));
    // stp: step
    for (int stp = 1; stp <= n; ++stp) {
      for (int i = 0; i + stp - 1 < n; ++i) {
        int j = i + stp - 1;
        m_C[i][j] = s.substr(i, stp);
        for (int k = i; k < j; ++k) {
          auto l = m_C[i][k];
          auto r = m_C[k+1][j];
          if (l.size() + r.size() < m_C[i][j].size())
            m_C[i][j] = l + r;
        }
        std::string replace = kstring(s, i, j);
        if (replace.size() < m_C[i][j].size())
          m_C[i][j] = replace;
      }
    }
    return m_C[0][n-1];
  }
};

int main() {

  Solution sln;
  printf("%s\n", sln.encode("aaaaaaaaaaaaaaaa").c_str());
  
  return 0;
}
