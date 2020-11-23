// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

struct DisjointSet {
  std::vector<int> parent, rank;
  explicit DisjointSet(int n) : parent(n), rank(n, 1) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }
  int find(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (rank[u] > rank[v])
      std::swap(u, v);
    // always rank[v] > rank[u] u should be child of v
    parent[u] = v;
    if (rank[u] == rank[v])
      ++rank[v];
  }
};

int kruskal(int n, std::vector<std::vector<std::pair<int, int>>> &adj, std::vector<std::pair<int, int>> &mst) {
  int r = 0;
  mst.clear();
  std::vector<std::pair<int, std::pair<int, int>>> edges;
  for (int u = 0; u < n; ++u) {
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i].first;
      int c = adj[u][i].second;
      edges.push_back(std::make_pair(c, std::make_pair(u, v)));
    }
  }
  std::sort(edges.begin(), edges.end());
  DisjointSet ds(n);
  for (int i = 0; i < edges.size(); ++i) {
    int c = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    if (ds.find(u) == ds.find(v))
      continue;
    ds.merge(u, v);
    mst.push_back(std::make_pair(u, v));
    r += c;
  }
  return r;
}

int main() {
  int n = 7;
  std::vector<std::vector<std::pair<int, int>>> adj(
      n, std::vector<std::pair<int, int>>());

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

  std::vector<std::pair<int, int>> mst;
  printf("%d\n", kruskal(n, adj, mst));

  for (const std::pair<int, int>& e : mst) {
    printf("%d -> %d\n", e.first, e.second);
  }

  return 0;
}
