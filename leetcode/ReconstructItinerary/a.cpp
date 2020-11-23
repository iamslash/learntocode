/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <queue>
#include <unordered_map>
#include <algorithm>

class Solution {
 private:
  std::unordered_map<std::string,
                     std::priority_queue<std::string,
                                         std::vector<std::string>,
                                         std::greater<std::string>>> m_adj;
  std::vector<std::string> m_path;
  void dfs(std::string u) {
    auto& pq = m_adj[u];
    while (!pq.empty()) {
      std::string v = pq.top();
      pq.pop();
      dfs(v);
    }
    m_path.push_back(u);
  }
 public:
  std::vector<std::string> findItinerary(
      std::vector<std::pair<std::string, std::string>> G) {
    for (const auto& p : G)
      m_adj[p.first].push(p.second);
    dfs("JFK");
    std::reverse(m_path.begin(), m_path.end());
    return m_path;
  }
};

int main() {

  // std::vector<std::pair<std::string, std::string>> G = {
  //   {"MUC", "LHR"},
  //   {"JFK", "MUC"},
  //   {"SFO", "SJC"},
  //   {"LHR", "SFO"},
  // };
  std::vector<std::pair<std::string, std::string>> G = {
    {"JFK", "SFO"},
    {"JFK","ATL"},
    {"SFO","ATL"},
    {"ATL","JFK"},
    {"ATL","SFO"}};
  Solution sln;
  auto path = sln.findItinerary(G);
  for (const auto& a : path)
    printf("%s ", a.c_str());
  printf("\n");
  
  return 0;
}
