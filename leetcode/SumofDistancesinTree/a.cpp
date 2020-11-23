/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

// 220ms 23.49% 42.3MB 36.11%
// O(N) O(N)
class Solution {
 private:
  std::vector<std::unordered_set<int>> m_adj;
  std::vector<int> m_rst;
  std::vector<int> m_cnt;
  int m_N;
  void dfs_post(int u, std::unordered_set<int>& seen) {
    seen.insert(u);
    for (int v : m_adj[u]) {
      if (seen.count(v) == 0) {
        dfs_post(v, seen);
        m_cnt[u] += m_cnt[v];
        m_rst[u] += m_rst[v] + m_cnt[v];
      }
    }
    m_cnt[u] += 1;
  }
  void dfs_pre(int u, std::unordered_set<int>& seen) {
    seen.insert(u);
    for (int v : m_adj[u]) {
      if (seen.count(v) == 0) {
        m_rst[v] = m_rst[u] - m_cnt[v] + m_N - m_cnt[v];
        dfs_pre(v, seen);
      }
    }
    
  }  
 public:
  std::vector<int> sumOfDistancesInTree(
      int N, std::vector<std::vector<int>>& E) {
    m_adj = std::vector<std::unordered_set<int>>(N);
    m_rst = std::vector<int>(N, 0);
    m_cnt = std::vector<int>(N, 0);
    m_N = N;
    if (N == 1)
      return m_rst;
    for (auto& e : E) {
      m_adj[e[0]].insert(e[1]);
      m_adj[e[1]].insert(e[0]);
    }
    std::unordered_set<int> seen_post;
    std::unordered_set<int> seen_pre;
    dfs_post(0, seen_post);
    dfs_pre(0, seen_pre);
    return m_rst;
  }
};

int main() {

  std::vector<std::vector<int>> E = {{0,1},{0,2},{2,3},{2,4},{2,5}};
  int N = 6;

  Solution sln;
  auto r = sln.sumOfDistancesInTree(N, E);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
