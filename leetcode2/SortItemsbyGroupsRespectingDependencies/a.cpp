/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// 848ms 6.71% 102.8MB 13.79%
// double topological sort
// O(N^2) O(N^2)
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
  Graph(vector<int>& A) {
    adj = unordered_map<int, vector<int>>();
    indeg = unordered_map<int, int>();
    for (int u : A) {
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
    for (auto& pr : indeg) {
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
class Solution {
 public:
  vector<int> sortItems(int n, int m, vector<int>& G,
                        vector<vector<int>>& B) {
    vector<vector<int>> groupItems(m, vector<int>());
    for (int u = 0; u < n; ++u) {
      if (G[u] >= 0) {
        groupItems[G[u]].push_back(u);
      } else {
        G[u] = groupItems.size();
        groupItems.push_back(vector<int>{u});
      }      
    }
    Graph groupGraph = Graph(groupItems.size());
    vector<Graph> groupItemGraphs(groupItems.size());
    for (int u = 0; u < groupItems.size(); ++u) {
      groupItemGraphs[u] = Graph(groupItems[u]);
    }
    // add edges
    for (int u = 0; u < n; ++u) {
      for (int v : B[u]) {
        int groupId = G[u];
        if (groupId == G[v]) {
          // u, v is in same group
          // add edge of items
          groupItemGraphs[groupId].addEdge(v, u);
        } else {
          // u, v is in different group
          // add edge of groups
          groupGraph.addEdge(G[v], groupId);
        }
      }
    }
    // topological sort
    vector<int> groupOrder = groupGraph.sort();
    vector<int> ans;
    if (groupOrder.size() < groupItems.size())
      return ans;
    for (int groupId : groupOrder) {
      vector<int> itemOrder = groupItemGraphs[groupId].sort();
      if (itemOrder.size() < groupItems[groupId].size()) {
        return {};
      }      
      for (int u : itemOrder) {
        ans.push_back(u);          
      }
    }
    return ans;
  }
};
