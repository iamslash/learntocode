/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>

// 16ms 7.36% 9.4MB 50.67%
class Solution {
 private:
  std::set<char> m_V;
  std::unordered_map<char, std::unordered_set<char>> m_G;
  std::unordered_map<char, bool> m_seen;
  std::string m_order;
  void dfs(char u) {
    m_seen[u] = true;
    // traverse neightbor
    if (m_G.count(u)) {
      for (char v : m_G[u]) {
        if (m_seen[v] == false)
          dfs(v);
      }
    }

    m_order.push_back(u);
  }
 public:
  std::string alienOrder(std::vector<std::string>& W) {
    if (W.size() == 0)
      return "";
    m_V.insert(W[0].begin(), W[0].end());
    for (int i = 1; i < W.size(); ++i) {
      m_V.insert(W[i].begin(), W[i].end());
      int nmin = std::min(W[i-1].size(), W[i].size());
      for (int j = 0; j < nmin; ++j) {
        if (W[i-1][j] != W[i][j]) {
          char u = W[i-1][j];
          char v = W[i][j];
          m_G[u].insert(v);
          break;
        }        
      }
    }
    for (char c : m_V)
      m_seen[c] = false;

    // for (auto& pr : m_G) {
    //   int u = pr.first;
    //   for (int v : pr.second) {
    //     printf("(%c, %c) ", u, v);
    //   }
    // }
    // printf("\n");
    // for (char c : m_V)
    //   printf("%c ", c);
    // printf("\n");
    
    // dfs all
    for (char u : m_V) {
      if (m_seen[u] == false)
        dfs(u);
    }

    // reverse
    std::reverse(m_order.begin(), m_order.end());

    // check back edge
    int n = m_order.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        char u = m_order[i];
        char v = m_order[j];
        // printf("%c %c %d %d\n", v, u, m_G.count(v), m_G[v].count(u));        
        if (m_G.count(v) > 0 && m_G[v].count(u) > 0)
          return "";
      }
    }    

    return m_order;
  }  
};

int main() {
  // std::vector<std::string> W =  {
  //   "wrt",
  //   "wrf",
  //   "er",
  //   "ett",
  //   "rftt"
  // };
  // std::vector<std::string> W =  {
  //   "z",
  //   "x"
  // };
  // std::vector<std::string> W =  {
  //   "z",
  //   "x",
  //   "z"
  // };
  std::vector<std::string> W =  {
    "za", "zb", "ca", "cb"
  };
  
  Solution sln;
  printf("%s\n", sln.alienOrder(W).c_str());
  
  return 0;
}
