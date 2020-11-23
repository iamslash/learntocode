/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 1 2 3
// 4 5 6
// 7 8 9

// 20ms 76.42% 6.5MB 5.50%
// back tracking
// O(N!) O(N)
class Solution {
 private:
  int dfs(vector<int>& seen, vector<vector<int>>& bridge,
          int u, int remain) {
    // base
    if (remain < 0)
      return 0;
    if (remain == 0)
      return 1;
    seen[u] = 1;    
    // recursion
    int ans = 0;
    for (int v = 1; v <= 9; ++v) {
      if (seen[v])
        continue;
      if (bridge[u][v] != 0 && seen[bridge[u][v]] == 0)
        continue;
      ans += dfs(seen, bridge, v, remain-1);
    }
    seen[u] = 0;
    return ans;
  }
 public:
  int numberOfPatterns(int m, int n) {
    vector<vector<int>> bridge(10, vector<int>(10));
    bridge[1][3] = bridge[3][1] = 2;
    bridge[1][7] = bridge[7][1] = 4;
    bridge[3][9] = bridge[9][3] = 6;
    bridge[7][9] = bridge[9][7] = 8;
    bridge[1][9] = bridge[9][1] =
        bridge[2][8] = bridge[8][2] =
        bridge[3][7] = bridge[7][3] =
        bridge[4][6] = bridge[6][4] = 5;
    vector<int> seen(10);
    int ans = 0;
    for (int i = m; i <= n; ++i) {
      ans += dfs(seen, bridge, 1, i-1) * 4;
      ans += dfs(seen, bridge, 2, i-1) * 4;
      ans += dfs(seen, bridge, 5, i-1);
    }
    return ans;
  }
};
