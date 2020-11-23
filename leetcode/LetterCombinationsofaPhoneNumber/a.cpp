/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 0ms 100.00%
// O(N^3) O(1)
class Solution {
 private:
  std::string m_comb;
  std::vector<std::string> m_rslt;
  std::vector<std::vector<char>> m_D;
  void solve(const std::string& s, int i) {
    // base
    if (i >= s.size()) {
      m_rslt.push_back(m_comb);
      return;
    }      

    // skip '1' '0' '*' '#'
    int d = s[i] - '2';
    if (d < 0 || d > 7) {
      solve(s, i+1);
      return;
    }

    // recursion
    for (int j = 0; j < m_D[d].size(); ++j) {
      char c = m_D[d][j];
      m_comb[i] = c;
      solve(s, i+1);
    }
  }
 public:
  std::vector<std::string> letterCombinations(const std::string& s) {
    if (s.empty())
      return m_rslt;
    m_D = {
      {'a', 'b', 'c'},
      {'d', 'e', 'f'},
      {'g', 'h', 'i'},
      {'j', 'k', 'l'},
      {'m', 'n', 'o'},
      {'p', 'q', 'r', 's'},
      {'t', 'u', 'v'},
      {'w', 'x', 'y', 'z'}
    };
    m_comb = std::string(s.size(), ' ');
    solve(s, 0);
    return m_rslt;
  }
};

int main() {

  Solution sln;
  auto rslt = sln.letterCombinations("23");
  for (const auto& s : rslt) {
    printf("%s\n", s.c_str());
  }
  
  return 0;
}
