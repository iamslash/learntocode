/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

// 272ms 77.11% 40.7MB 61.17%
// disjointset
// O(N^2) O(N)
class DisjointSet {
 private:
  vector<int> prnt;
 public:
  DisjointSet(int n) : prnt(n) {
    for (int i = 0; i < n; ++i)
      prnt[i] = i;
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    prnt[u] = v;
  }
  int find(int u) {
    if (prnt[u] == u)
      return u;
    return prnt[u] = find(prnt[u]);
  }
};

class Solution {
 public:
  int largestComponentSize(vector<int>& A) {
    int n = *max_element(A.begin(), A.end());
    DisjointSet ds(n+1);
    for (int a : A) {
      for (int k = 2; k <= sqrt(a); ++k) {
        if (a % k == 0) {
          ds.merge(a, k);
          ds.merge(a, a/k);
        }
      }
    }
    unordered_map<int, int> ump;
    int ans = 1;
    for (int a : A) {
      ans = max(ans, ++ump[ds.find(a)]);
    }
    return ans;
  }
};
