/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>

// backtracking
// 4ms 100.00% 8.6Mㅠ 92.59%
class Solution {
 private:
  std::vector<int> m_freqs;                // frequency of i+'a'
  std::vector<std::string> m_combs;        // combination pattern string of i+'a'
  std::unordered_set<std::string> m_used;  // used patterns
  std::string m_ptn;
  std::string m_str;
  //  ppos: pattern position to match
  //  spos: string position to match
  // lobnd: 
  bool dfs(int ppos, int spos, int lobnd) {
    // base
    if (ppos == m_ptn.size() || spos == m_str.size())
      return ppos == m_ptn.size() && spos == m_str.size();

    // recursion
    char  c = m_ptn[ppos];
    auto& s = m_combs[c-'a'];

    if (s.empty()) {
      for (int len = 1; spos + len <= m_str.size(); ++len) {
        s += m_str[spos + len - 1];
        if (m_used.count(s))
          continue;
        auto nlobnd = lobnd + m_freqs[c-'a'] * (len-1);
        if (m_str.size() < nlobnd)
          break;
        auto it = m_used.insert(s).first;
        if (dfs(ppos+1, spos+len, nlobnd))
          return true;
        m_used.erase(it);
      }
      s.clear();
      return false;
    }
    return m_str.substr(spos, s.size()) == s &&
        dfs(ppos+1, spos+s.size(), lobnd);
  }
 public:
  bool wordPatternMatch(std::string ptn, std::string str) {
    m_freqs = std::vector<int>(26, 0);
    m_combs = std::vector<std::string>(26, "");
    m_ptn = ptn;
    m_str = str;
    for (auto c : ptn)
      ++m_freqs[c-'a'];
    return dfs(0, 0, ptn.size());
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  Solution sln;
  printb(sln.wordPatternMatch("abab", "redblueredblue"));
  printb(sln.wordPatternMatch("aaaa", "asdasdasdasd"));
  printb(sln.wordPatternMatch("aabb", "xyzabcxzyabc"));
  
  return 0;
}
