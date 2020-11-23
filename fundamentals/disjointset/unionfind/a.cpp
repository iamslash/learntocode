// Copyright (C) 2016 by iamslash

#include <vector>

struct NaiveDisjointSet {
  std::vector<int> parent;
  explicit NaiveDisjointSet(int n) : parent(n) {
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }
  int find(int u) const {
    if (u == parent[u]) return u;
    return find(parent[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    parent[u] = v;
  }
};

struct OptimizedDisjointSet {
  std::vector<int> parent, rank;
  explicit OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
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

int main() {
  OptimizedDisjointSet uf(10);
  uf.merge(0, 5);
  uf.merge(4, 8);
}
