/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

// 624ms 64.20% 91.6MB 41.33%
// DFS
// O(N) O(N)
class Solution {
 private:
  int dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visit, int u) {
    // printf("%d\n", u);
    // base
    visit[u] = true;
    // recursion
    int ans = 0;
    for (int v : adj[u]) {
      if (visit[abs(v)])
        continue;
      ans += int(v > 0);
      ans += dfs(adj, visit, abs(v));
    }
    return ans;
  }
 public:
  int minReorder(int n, vector<vector<int>>& cons) {
    unordered_map<int, vector<int>> adj;
    for (int u = 0; u < n; ++u)
      adj[u] = vector<int>();
    for (auto& con : cons) {
      int u = con[0];
      int v = con[1];
      adj[u].push_back(v);
      adj[v].push_back(-u);
    }
    vector<bool> visit(n, false);
    return dfs(adj, visit, 0);
  }
};
