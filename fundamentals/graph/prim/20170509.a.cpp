// Copyright (C) 2016 by iamslash

// Prim algorithm
//
// 0. min_weight, parent
// 1. select edges, vertices which are connected and have min weight.

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

const int MAX_V = 100;
const int MAX_I = 987654321;
int V = 7;
std::vector<std::pair<int, int> > adj[MAX_V];

int Prim(std::vector<std::pair<int, int> > * selected) {
  int r = 0;
  selected->clear();
  std::vector<bool> added(V, false);
  std::vector<int> min_weight(V, MAX_I);
  std::vector<int> parent(V, -1);
  min_weight[0] = parent[0] = 0;
  // O(|V||V|)
  // O(|V|^2+|E|)
  for (int iter = 0; iter < V; ++iter) {
    int u = -1;
    for (int v = 0; v < V; ++v) {
      if (!added[v] &&
          (u == -1 || min_weight[u] > min_weight[v]))
        u = v;
      if (parent[u] != u)
        selected->push_back(std::make_pair(parent[u], u));
      r += min_weight[u];
      added[u] = true;
      for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int weight = adj[u][i].second;
        if (!added[v] && min_weight[v] > weight) {
          parent[v] = u;
          min_weight[v] = weight;
        }
      }
    }
  }

  return r;
}

int main() {
  for (int i = 0; i < MAX_V; ++i)
    adj[i].clear();

  adj[0].push_back(std::make_pair(1, 5));
  adj[0].push_back(std::make_pair(2, 1));

  adj[1].push_back(std::make_pair(0, 5));
  adj[1].push_back(std::make_pair(3, 1));
  adj[1].push_back(std::make_pair(4, 3));
  adj[1].push_back(std::make_pair(5, 3));

  adj[2].push_back(std::make_pair(0, 1));
  adj[2].push_back(std::make_pair(3, 4));

  adj[3].push_back(std::make_pair(1, 1));
  adj[3].push_back(std::make_pair(2, 4));
  adj[3].push_back(std::make_pair(4, 5));
  adj[3].push_back(std::make_pair(5, 3));

  adj[4].push_back(std::make_pair(3, 5));

  adj[5].push_back(std::make_pair(1, 3));
  adj[5].push_back(std::make_pair(3, 3));
  adj[5].push_back(std::make_pair(6, 2));

  adj[6].push_back(std::make_pair(1, 3));
  adj[6].push_back(std::make_pair(5, 2));

  std::vector<std::pair<int, int> > r;
  printf("%d\n", Prim(&r));

  for (const std::pair<int, int>& p : r) {
    printf("%d -> %d\n", p.first, p.second);
  }

  return 0;
}
