/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// 4ms 3.98%
class Solution {
 private:
  std::unordered_set<std::string> m_nodes;
  std::unordered_map<std::string, std::unordered_map<std::string, double>> m_dists;
  void floyd() {
    // k, i, j
    for (const std::string k : m_nodes) {
      for (const std::string i : m_nodes) {
        for (const std::string j : m_nodes) {
          if (m_dists.count(i) == 0 ||
              m_dists.count(k) == 0 ||              
              m_dists[i].count(k) == 0 ||
              m_dists[k].count(j) == 0 )
            continue;
          if (m_dists[i].count(j) == 0 ||
              m_dists[i][j] > m_dists[i][k] + m_dists[k][j]) {
            m_dists[i][j] = m_dists[i][k] * m_dists[k][j];
            // printf("dists[%s][%s] = %0.1lf\n", i.c_str(), j.c_str(), m_dists[i][j]);
          }
        }
      }
    }
  }
 public:
  std::vector<double> calcEquation(std::vector<std::pair<std::string, std::string>> E,
                                   std::vector<double>& V,
                                   std::vector<std::pair<std::string, std::string>> Q) {

    for (int i = 0; i < E.size(); ++i) {
      m_dists[E[i].first][E[i].second] = V[i];
      m_dists[E[i].second][E[i].first] = 1/V[i];
      m_nodes.insert(E[i].first);
      m_nodes.insert(E[i].second);
    }
    
    floyd();

    std::vector<double> rslt;
    for (const auto& pr : Q) {
      double d = -1.0;
      if (m_dists.count(pr.first) > 0) {
        if (pr.first == pr.second)
          d = 1.0;
        else if (m_dists[pr.first].count(pr.second) > 0)
          d = m_dists[pr.first][pr.second];
      }              
      rslt.push_back(d);
    }
    return rslt;
  }
};

int main() {
  std::vector<std::pair<std::string, std::string>> E = {{"a", "b"},{"b", "c"}};
  std::vector<double> V = {2.0, 3.0};
  std::vector<std::pair<std::string, std::string>> Q = {
    {"a", "c"},
    {"b", "a"},
    {"a", "e"},
    {"a", "a"},
    {"x", "x"}
  };

  Solution sln;
  const auto& rslt = sln.calcEquation(E, V, Q);
  for (double d : rslt)
    printf("%0.1lf ", d);
  printf("\n");
  return 0;
}
