/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 52ms 89.66% 30.4MB 100.00%
// DFS
// O(N) O(N)
class Solution {
 private:
  bool dfs(vector<int>& seen, vector<int>& L, vector<int>& R, int u) {
    // base
    if (u < 0)
      return true;
    if (seen[u])
      return false;
    seen[u] = true;
    // recursion
    return dfs(seen, L, R, L[u]) &&
        dfs(seen, L, R, R[u]);
  }
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& L, vector<int>& R) {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    if (n == 1)
      return true;
    vector<int> seen(n, 0);
    for (int u = 0; u < n; ++u) {
      if (L[u] >= 0 || R[u] >= 0) {
        if (!dfs(seen, L, R, u))
          return false;
        break;
      }
    }
    for (int a : seen) {
      if (a == 0)
        return false;
    }
    return true; 
  }
};
