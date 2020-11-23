/* Copyright (C) 2020 by iamslash */

#include <cstdio>

// 56ms 13.33% 10.9MB 58.40%
// DFS
// O(N) O(N)
class Solution {
 private:
  int ans;
  int dfs(Node* u) {
    // base
    if (u == NULL)
      return 0;
    // recursion
    int cost_1st = 0, cost_2nd = 0;
    for (Node* v : u->children) {
      int cost = dfs(v);
      if (cost > cost_1st) {
        cost_2nd = cost_1st;
        cost_1st = cost;
      } else if (cost > cost_2nd) {
        cost_2nd = cost;
      }
    }
    ans = max(ans, cost_1st + cost_2nd);
    return cost_1st + 1;
  }
 public:
  int diameter(Node* u) {
    dfs(u);
    return ans;
  }
};
