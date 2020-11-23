/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// 380ms 20.66% 48.6MB 10.30%
// hash map
// O(N^2) O(N^2)
class Solution {
 private:
  unordered_map<int, unordered_map<int, int>> G;
  unordered_set<int> unhappySet;
  void checkHappy(int x, int y, int u, int v) {
    if (G[u][x] < G[y][x] &&
        G[x][u] < G[v][u]) {
      unhappySet.insert(x);
      unhappySet.insert(u);
    }
  }
 public:
  int unhappyFriends(int n,
                     vector<vector<int>>& prefs,
                     vector<vector<int>>& pairs) {
    for (int u = 0; u < n; ++u) {
      for (int j = 0; j < n-1; j++) {
        int v = prefs[u][j];
        G[v][u] = j;
      }
    }
    int m = pairs.size();
    for (int i = 0; i < m - 1; ++i) {
      for (int j = i+1; j < m; ++j) {
        int x = pairs[i][0];
        int y = pairs[i][1];
        int u = pairs[j][0];
        int v = pairs[j][1];
        checkHappy(x, y, u , v); // x prefers u over y, and u prefers x over v ?
        checkHappy(x, y, v , u); // x prefers v over y, and v prefers x over u ?
        checkHappy(y, x, u , v); // y prefers u over x, and u prefers y over v ?
        checkHappy(y, x, v , u); // y prefers v over x, and v prefers y over u ?
      }
    }
    return unhappySet.size();
  }
};
