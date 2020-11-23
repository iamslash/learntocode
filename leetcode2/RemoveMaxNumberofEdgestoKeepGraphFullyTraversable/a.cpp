/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// 908ms 98.49% 138.3MB 84.35%
// merge find
class DisjointSet {
 private:
  vector<int> prnt;
  int size;
 public:
  DisjointSet(int n) : prnt(n), size(n) {
    iota(begin(prnt), end(prnt), 0);
  }
  int find(int u) {
    if (prnt[u] == u)
      return u;
    return prnt[u] = find(prnt[u]);
  }
  int connected(int u, int v) {
    return find(u) == find(v);
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    prnt[u] = v;
    --size;
  }
  int getSize() {
    return size;
  }
};
class Solution {
 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& E) {
    DisjointSet dsAlice(n), dsBob(n);
    int ans = 0;
    for (auto& e : E) {
      if (e[0] != 3)
        continue;
      int u = e[1] - 1;
      int v = e[2] - 1;
      if (dsAlice.connected(u, v)) {
        ++ans;
        continue;
      }
      dsAlice.merge(u, v);
      dsBob.merge(u, v);
    }
    for (auto& e : E) {
      int u = e[1] - 1;
      int v = e[2] - 1;
      if (e[0] == 1) {
        if (dsAlice.connected(u, v)) {
          ++ans;
        } else {
          dsAlice.merge(u, v);
        }
      } else if (e[0] == 2) {
        if (dsBob.connected(u, v)) {
          ++ans;
        } else {
          dsBob.merge(u, v);
        }
      }
    }
    if (dsAlice.getSize() != 1 || dsBob.getSize() != 1)
        return -1;
    return ans;
  }
};
