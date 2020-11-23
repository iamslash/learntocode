// Copyright (C) 2018 by iamslash
// https://www.geeksforgeeks.org/dynamic-connectivity-set-1-incremental/

#include <cstdio>
#include <vector>

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

int V, E;

void solve(DisjointSet& ds, int t, int x, int y) {
  if (t == 1) {
    if (ds.find(x) == ds.find(y))
      printf("Yes");
    else
      printf("No");
    printf("\n");
  } else {
    ds.merge(x, y);
  }
}

int main() {
  scanf("%d %d", &V, &E);
  DisjointSet ds(V);
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    solve(ds, a, b, c);
  }  
  return 0;
}
