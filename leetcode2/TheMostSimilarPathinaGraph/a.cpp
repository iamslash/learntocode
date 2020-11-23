/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// Wrong Answer
// 5
// [[0,2],[0,3],[1,2],[1,3],[1,4],[2,4]]
// ["ATL","PEK","LAX","DXB","HND"]
// ["ATL","DXB","HND","LAX"]
class Solution {
 private:
  int dfs(vector<vector<int>>& visit, vector<vector<int>>& next,
          vector<unordered_set<int>>& G, vector<string>& names,
          vector<string>& paths, int nameIdx, int pathIdx) {
    // base
    if (visit[nameIdx][pathIdx] != -1)
      return visit[nameIdx][pathIdx];
    int editDist = 1;
    if (names[nameIdx] == paths[pathIdx])
      editDist = 0;
    if (pathIdx == paths.size() - 1)
      return editDist;
    // recursion
    int minCost = INT_MAX;
    for (int v : G[nameIdx]) {
      int vCost = dfs(visit, next, G, names, paths, v, pathIdx+1);
      if (vCost < minCost) {
        minCost = vCost;
        next[nameIdx][pathIdx] = v;
      } 
    }
    editDist += minCost;
    visit[nameIdx][pathIdx] = editDist;
    return editDist;
  }
 public:
  vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names,
                          vector<string>& targetPath) {
    vector<vector<int>> visit(names.size(), vector<int>(targetPath.size(), -1));
    vector<vector<int>> next(names.size(), vector<int>(targetPath.size(), 0));
    vector<unordered_set<int>> G(n);
    // build G
    for (auto& e : roads) {
      int u = e[0], v = e[1];
      G[u].insert(v);
      G[v].insert(u);
    }
    // get min cost and the city
    int minCost = INT_MIN;
    int beg = 0;
    for (int u = 0; u < names.size(); ++u) {
      int cost = dfs(visit, next, G, names, targetPath, u, 0);
      if (cost < minCost) {
        minCost = cost;
        beg = u;
      }
    }
    //
    vector<int> ans;
    while (ans.size() < targetPath.size()) {
      ans.push_back(beg);
      beg = next[beg][ans.size()-1];
    }
    return ans;
  }
};
