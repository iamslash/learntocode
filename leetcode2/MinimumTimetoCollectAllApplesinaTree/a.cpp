/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//   n : 7
//   E : [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]
//           i
//   B : [f t t f t t f]
// cnt : 4

//   n : 4
//   E : [[0,2],[0,3],[1,2]]
//                       i
//   B : f t f f
// cnt :0

// // 760ms 9.91% 75MB 19.42%
// // DFS
// // O(N) O(N)
// class Solution {
//  private:
//   int dfs(unordered_map<int, vector<int>>& G,
//           unordered_set<int>& visit,
//           vector<bool>& B, int u, int cost) {
//     // base
//     if (visit.count(u))
//       return 0;
//     visit.insert(u);
//     // recursion
//     int childCost = 0;
//     for (int v: G[u])
//       childCost += dfs(G, visit, B, v, 2);
//     if (childCost == 0 && B[u] == false)
//       return 0;
//     return cost + childCost;
//   }
//  public:
//   int minTime(int n, vector<vector<int>>& E, vector<bool>& B) {
//     unordered_map<int, vector<int>> G;
//     unordered_set<int> visit;
//     for (auto& e : E) {
//       G[e[0]].push_back(e[1]);
//       G[e[1]].push_back(e[0]);      
//     }
//     return dfs(G, visit, B, 0, 0);
//   }
// };

// 652ms 16.10% 68.3MB 32.63%x
// DFS
// O(N) O(N)
class Solution {
 private:
  int dfs(unordered_map<int, vector<int>>& G,
          vector<bool>& B, int u, int p) {
    int cost = 0;
    for (int v : G[u]) {
      if (v == p)
        continue;
      cost += dfs(G, B, v, u);
    }
    if (u != 0 && (B[u] || cost > 0))
      cost += 2;
    return cost;
  }
 public:
  int minTime(int n, vector<vector<int>>& E, vector<bool>& B) {
    unordered_map<int, vector<int>> G;
    for (auto& e : E) {
      G[e[0]].push_back(e[1]);
      G[e[1]].push_back(e[0]);      
    }
    return dfs(G, B, 0, -1);
  }  
};
