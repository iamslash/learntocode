/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// 596ms 51.73% 73.1MB 25.36%
// BFS
// O(V+E) O(V)
class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& E, vector<double>& P,
                        int start, int end) {
    vector<double> ans(n, 0.0);
    ans[start] = 1.0;
    vector<unordered_map<int, double>> G(n, unordered_map<int, double>());
    for (int i = 0; i < E.size(); ++i) {
      int u = E[i][0], v = E[i][1];
      G[u][v] = P[i];
      G[v][u] = P[i];
    }
    queue<int> q;
    q.push(start);
    while (q.size()) {
      int u = q.front(); q.pop();
      for (auto& pr : G[u]) {
        int v = pr.first;
        double cost = pr.second * ans[u];
        if (cost > ans[v]) {
          q.push(v);
          ans[v] = cost;
        }
      }
    }
    return ans[end];
  }
};
