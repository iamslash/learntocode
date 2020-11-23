/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

// graph:     
// 1 1 1 1      
// 1 2 2 1    
// 1 2 2 1    
// 1 1 1 1
//
// overlaps: 1
//           2
//
// visit: 2 2

// graph:     
// 1 1 1 1      
// 1 2 2 1    
// 1 2 2 1    
// 1 1 1 2
//
// overlaps: 1 2 
//           2 1 
//
// visit: 1 1 

// DFS
// O(HW) O(HW)
class Solution {
 private:
  bool dfs(unordered_set<int> overlaps[], int u, vector<int>& visit) {
    // base
    if (visit[u] != 0)
      return visit[u] == 2;
    // recursion
    visit[u] = 1;
    for (int v : overlaps[u]) {
      if (dfs(overlaps, v, visit) == false)
        return false;
    }
    visit[u] = 2;
    return true;
  }
 public:
  bool isPrintable(vector<vector<int>>& G) {
    vector<vector<int>> rects(61, {INT_MAX, INT_MAX, INT_MIN, INT_MIN});
    unordered_set<int> overlaps[61]; // {color: {overlaped color,...}}
    for (int y = 0; y < G.size(); ++y) {
      for (int x = 0; x < G[0].size(); ++x) {
        int col = G[y][x];
        rects[col][0] = min(rects[col][0], y);
        rects[col][1] = min(rects[col][1], x);
        rects[col][2] = max(rects[col][2], y);
        rects[col][3] = max(rects[col][3], x);
      }
    }
    for (int col = 0; col <= 60; ++col) {
      for (int y = rects[col][0]; y <= rects[col][2]; ++y) {
        for (int x = rects[col][1]; x <= rects[col][3]; ++x) {
          if (G[y][x] != col) {
            overlaps[col].insert(G[y][x]);
          }
        }
      }
    }
    for (int col = 0; col <= 60; ++col) {
      if (dfs(overlaps, col, vector<int>(61) = {}) == false) {
        return false;
      }
    }
    return true;
  }
};
