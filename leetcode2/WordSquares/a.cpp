/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

// 104ms 55.49% 24.5MB 21.43%
// prefix
// O(W^N) (N)
class Solution {
 private:
  int m_n;
  // {prefix : word, ...}
  std::unordered_map<std::string, std::vector<std::string>> m_prf2wrd;
  std::vector<std::string> m_comb;   // combination
  std::vector<std::vector<std::string>> m_rslt;  // result

  void build(int i) {
    // base
    if (i == m_n) {
      m_rslt.push_back(m_comb);
    }
    
    // recursion
    std::string prf;  // prefix
    for (int j = 0; j < i; ++j)
      prf += m_comb[j][i];
    for (std::string s : m_prf2wrd[prf]) {
      // printf("%d %s\n", i, s.c_str());
      m_comb[i] = s;
      build(i + 1);
    }
  }
 public:
  std::vector<std::vector<std::string>> wordSquares(
      std::vector<std::string>& W) {
    m_n = W[0].size();
    m_comb.resize(m_n);
    for (auto& s : W) {
      for (int i = 0; i < m_n; ++i) {
        std::string key = s.substr(0, i);
        m_prf2wrd[key].push_back(s);
        // printf("%s : %s\n", key.c_str(), s.c_str());
      }
    }
    build(0);
    return m_rslt;
  }
};

int main() {

  std::vector<std::string> W = {"ball","area","lead","lady"};
  Solution sln;
  auto r = sln.wordSquares(W);
  for (auto& l : r) {
    for (auto& s : l)
      printf("%s\n", s.c_str());
    printf("\n");
  }

  return 0;
}
