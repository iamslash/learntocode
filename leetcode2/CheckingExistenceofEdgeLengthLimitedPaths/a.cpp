/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// 1008ms 75.64% 110.2MB 73.94%
// Disjoint Set
// O(ElgE) O(N)
class DisjointSet {
 private:  
  vector<int> parent;
 public:
  DisjointSet(int n) : parent(n) {
    iota(parent.begin(), parent.end(), 0);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    parent[u] = v;
  }
  bool connected(int u, int v) {
    return find(u) == find(v);
  }
  int find(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = find(parent[u]);
  }  
};
class Solution {
 public:
  vector<bool> distanceLimitedPathsExist(
      int n,
      vector<vector<int>>& edgeList,
      vector<vector<int>>& queries) {
    vector<bool> ans(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(),
         [&](vector<int>& a, vector<int>& b) {
           return a[2] < b[2];
         });
    sort(edgeList.begin(), edgeList.end(),
         [&](vector<int>& a, vector<int>& b) {
           return a[2] < b[2];
         });
    DisjointSet ds(n);
    int j = 0;
    for (auto& q : queries) {
      int u = q[0], v = q[1], w = q[2];
      for (; j < edgeList.size(); ++j) {
        auto& e = edgeList[j];
        int x = e[0], y = e[1], z = e[2];
        if (z >= w)
          break;
        ds.merge(x, y);
      }
      ans[q[3]] = ds.connected(u, v);
    }
    return ans;
  }
};
