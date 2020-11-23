/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;


//  1d      0a
//    \   /   \
//      2e      3e

// // Wrong Answer
// // 4
// // [[0,2],[0,3],[1,2]]
// // "aeed"
// // DFS
// // O(N) O(N)
// class Solution {
//  private:
//   void dfs(vector<unordered_set<int>>& G, string& L,
//                   int cnt[], vector<int>& ans, int u) {
//     // recursion
//     for (int v : G[u]) {
//       int cnt2[26] = {0,};
//       dfs(G, L, cnt2, ans, v);
//       for (int i = 0; i < 26; ++i)
//         cnt[i] += cnt2[i];
//     }
//     ans[u] = ++cnt[L[u]-'a']; 
//   }
//  public:
//   vector<int> countSubTrees(int n, vector<vector<int>>& E, string L) {
//     vector<unordered_set<int>> G(n, unordered_set<int>());
//     for (int i = 0; i < E.size(); ++i) {
//       int u = E[i][0], v = E[i][1];
//       G[u].insert(v);
//     }
//     int cnt[26] = {0,};
//     vector<int> ans(n, 0);
//     dfs(G, L, cnt, ans, 0);
//     return ans;
//   }
// };


// 1132ms 66.21% 191.7MB 64.58%
// DFS
// O(N) O(N)
class Solution {
 private:
  void dfs(vector<unordered_set<int>>& G, string& L,
                  int cnt[], vector<int>& ans, int u) {
    // base
    if (ans[u] != 0)
      return;
    ans[u] = 1;
    // recursion
    for (int v : G[u]) {
      int cnt2[26] = {0,};
      dfs(G, L, cnt2, ans, v);
      for (int i = 0; i < 26; ++i)
        cnt[i] += cnt2[i];
    }
    ans[u] = ++cnt[L[u]-'a']; 
  }
 public:
  vector<int> countSubTrees(int n, vector<vector<int>>& E, string L) {
    vector<unordered_set<int>> G(n, unordered_set<int>());
    for (int i = 0; i < E.size(); ++i) {
      int u = E[i][0], v = E[i][1];
      G[u].insert(v);
      G[v].insert(u);
    }
    int cnt[26] = {0,};
    vector<int> ans(n, 0);
    dfs(G, L, cnt, ans, 0);
    return ans;
  }
};
