// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>

struct DisjointSet {
  std::vector<int> parent, rank, size;
  int maxsize;
  explicit DisjointSet(int n) : parent(n), rank(n, 1), size(n, 1), maxsize(0) {
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
    size[v] += size[u];
    if (maxsize < size[v])
      maxsize = size[v];
  }
};

int V, E;

int main() {
  scanf("%d %d", &V, &E);
  DisjointSet ds(V);
  for (int i = 0; i < E; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ds.merge(a, b);
  }
  printf("%d\n", ds.maxsize);
  return 0;
}
