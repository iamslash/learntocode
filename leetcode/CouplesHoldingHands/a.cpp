/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 0 2 1 3
// O(N) O(N)
struct DisjointSet {
  std::vector<int> parent, rank;
  int cnt;
  explicit DisjointSet(int n) : parent(n), rank(n, 1), cnt(0) {
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
    parent[u] = v;
    cnt++;
    if (rank[u] == rank[v])
      ++rank[v];
  }
};

class Solution {
 public:
  int minSwapsCouples(std::vector<int>& V) {
    int n = V.size() / 2;
    DisjointSet ds(n);
    for (int i = 0; i < n; ++i) {
      int a = V[2*i];
      int b = V[2*i + 1];
      ds.merge(a/2, b/2);
      // printf("i: %d, a/2: %d, b/2: %d, cnt: %d\n", i, a/2, b/2, ds.cnt);
    }
    return ds.cnt;
  }
};

int main() {
  std::vector<int> V = {0, 2, 1, 3};
  // std::vector<int> V = {3, 2, 0, 1};
  Solution sln;
  printf("%d\n", sln.minSwapsCouples(V));
  return 0;
}
