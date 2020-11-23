/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

class Solution {
public:
  std::vector<int> findMinHeightTrees(int n,
                                      const std::vector<std::pair<int, int>>& E) {
    // build a graph
    std::vector<std::unordered_set<int>> adj(n);
    for (auto e : E) {
      adj[e.first].insert(e.second);
      adj[e.second].insert(e.first);
    }

    // corner case
    std::vector<int> rslt;
    if (n == 1) {
      rslt.push_back(0);
      return rslt;
    }

    // push leaf nodes
    for (int i = 0; i < adj.size(); ++i) {
      if (adj[i].size() == 1) {
        rslt.push_back(i);
      }
    }

    // BFS
    while (true) {
      std::vector<int> q;
      for (int u : rslt) {
        for (int v : adj[u]) {
          adj[v].erase(u);
          if (adj[v].size() == 1)
            q.push_back(v);
        }
      }
      if (q.empty())
        return rslt;
      rslt = q;
    }
  }
};

int main() {

  // int n = 4;
  // std::vector<std::pair<int, int>> E = {{1, 0}, {1, 2}, {1, 3}};
  int n = 6;
  std::vector<std::pair<int, int>> E = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};

  Solution sln;
  auto rslt = sln.findMinHeightTrees(n, E);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");
  
  return 0;
}
