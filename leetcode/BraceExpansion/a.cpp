/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <set>

// 4ms 94.66% 10.4MB 80.00%
// backtracking
// O(2^S) O(lgS)
class Solution {
 private:
  std::vector<std::string> m_rslt;
  std::string m_cand;
  void dfs(std::vector<std::set<char>> &D, int i) {
    // base
    if (i >= D.size()) {
      m_rslt.push_back(m_cand);
      return;
    }

    // recursion
    for (char c : D[i]) {
      m_cand.push_back(c);
      dfs(D, i+1);
      m_cand.pop_back();
    }
  }
 public:
  std::vector<std::string> expand(std::string S) {
    std::vector<std::set<char>> D;

    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == '{') {
        ++i;
        D.push_back({});
        while (S[i+1] != '}') {
          D.back().insert(S[i]);
          i += 2;
        }
        D.back().insert(S[i++]);
      } else {
        D.push_back({S[i]});
      }
    }
      
    // for (auto &s : D) {
    //     for (char c : s) {
    //         printf("%c ", c);
    //     }
    //     printf("\n");
    // }

    dfs(D, 0);
    
    return m_rslt;
  }
};

int main() {
  // std::string s = "{a,b}c{d,e}f";
  std::string s = "abcd";

  Solution sln;
  auto r = sln.expand(s);
  for (auto &line : r) {
    for (char c : line)
      printf("%c ", c);
    printf("\n");
  }
  return 0;
}
