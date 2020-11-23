/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

//       i
// A: tars rats arts star
//       0    0    0    1
//            j
//

// 956ms 87.97%
// Disjoint Set
// O(N^2W) O(N)
class DisjointSet {
 private:
  vector<int> parent;
  int groupCnt;
 public:
  DisjointSet(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    groupCnt = n;
  }
  int find(int u) {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return;
    parent[u] = v;
    groupCnt--;
  }
  int group() {
    return groupCnt;
  }
};
class Solution {
 private:
  bool similar(const string& a, const string& b) {
    int n = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i] && ++n > 2) {
        return false;
      }
    }
    return true;
  }
 public:
  int numSimilarGroups(vector<string>& A) {
    int n = A.size();
    DisjointSet ds(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (similar(A[i], A[j]))
          ds.merge(i, j);
      }
    }
    return ds.group();
  }
};
