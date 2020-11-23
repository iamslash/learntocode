/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// 332ms 71.17% 65.8MB 6.13%
// Set-disjoint
// O(N) O(N)
class Solution {
 private:
  vector<int> parent;
  vector<int> rank;
  int find(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    if (rank[u] < rank[v]) {
      parent[u] = v;
      return;
    }
    parent[v] = u;
    if (rank[u] == rank[v])
      rank[u]++;
  }
 public:
  vector<bool> areConnected(int n, int threshold, vector<vector<int>>& Q) {
    parent.resize(n+1);
    rank.resize(n+1);
    iota(parent.begin(), parent.end(), 0);
    for (int i = threshold + 1; i <= n; ++i) {
      for (int j = 1; i*j <= n; ++j) {
        merge(i, i*j);
      }
    }
    vector<bool> ans(Q.size());
    for (int i = 0; i < Q.size(); ++i) {
      auto& q = Q[i];
      if (find(q[0]) == find(q[1]))
        ans[i] = true;
    }
    return ans;
  }
};
 
