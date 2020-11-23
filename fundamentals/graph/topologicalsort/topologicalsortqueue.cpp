/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Graph {
 private:
  unordered_map<int, vector<int>> adj;
  unordered_map<int, int> indeg;
 public:
  Graph() {}
  Graph(int n) {
    adj = unordered_map<int, vector<int>>();
    indeg = unordered_map<int, int>();
    for (int u = 0; u < n; ++u) {
      indeg[u] = 0;
      adj[u] = vector<int>();
    }
  }
  void addEdge(int u, int v) {
    adj[u].push_back(v);
    indeg[v]++;
  }
  // toplological sort
  vector<int> sort() {
    queue<int> q;
    vector<int> ord;
    for (int pr : indeg) {
      if (pr.second == 0)
        q.push(pr.first);
    }
    while (q.size()) {
      int u = q.front(); q.pop();
      ord.push_back(u);
      for (int v : adj[u]) {
        indeg[v]--;
        if (indeg[v] == 0)
          q.push(v);
      }
    }
    return ord;
  }
};
