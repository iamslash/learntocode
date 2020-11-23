/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 252ms 36.35% 19.7MB 100.00%
// kruskal's algorithm
// O(E^2lgE) O(V)
#define MAXINT 1000000007
class DisjointSet {
 private:
  vector<int> prnt, rank;
 public:
  DisjointSet(int n) {
    rank = vector<int>(n, 1);
    prnt.resize(n);
    for (int u = 0; u < n; ++u)
      prnt[u] = u;
  }
  int find(int u) {
    if (u == prnt[u])
      return u;
    return prnt[u] = find(prnt[u]);
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    if (rank[u] > rank[v])
      swap(u, v);
    prnt[u] = v;
    if (rank[u] == rank[v])
      rank[v]++;
  }
};

class Solution {
 private:
  int mst(const int n, const vector<vector<int>>& E, int exEdge, int inEdge = -1) {
    DisjointSet ds(n);
    int totalWeight = 0;
    if (inEdge >= 0) {
      totalWeight += E[inEdge][2];
      ds.merge(E[inEdge][0], E[inEdge][1]);
    }
    for (int i = 0; i < E.size(); ++i) {
      if (i == exEdge)
        continue;
      auto& edge = E[i];
      if (ds.find(edge[0]) == ds.find(edge[1]))
        continue;
      ds.merge(edge[0], edge[1]);
      totalWeight += edge[2];
    }
    for (int u = 0; u < n; ++u) {
      if (ds.find(u) != ds.find(0))
        return MAXINT;
    }
    return totalWeight;
  }
 public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(
      int n, vector<vector<int>>& E) {
    for (int i = 0; i < E.size(); ++i) {
      E[i].push_back(i);
    }
    sort(E.begin(), E.end(), [](const vector<int> &a, const vector<int> &b) {
                               return a[2] < b[2];
                             });
    int mstTotalWeight = mst(n, E, -1);
    vector<int> criticalEdges, pseudoEdges;
    for (int i = 0; i < E.size(); ++i) {
      if (mstTotalWeight < mst(n, E, i)) {
        criticalEdges.push_back(E[i][3]);
      } else if (mstTotalWeight == mst(n, E, -1, i)) {
        pseudoEdges.push_back(E[i][3]);
      }
    }
    return {criticalEdges, pseudoEdges};
  }
};
