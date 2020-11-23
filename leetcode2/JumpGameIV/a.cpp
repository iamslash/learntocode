/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// 288ms 70.14% 51.3MB 44.86%
// BFS
// O(N) O(N)
class Solution {
 public:
  int minJumps(vector<int>& A) {
    int n = A.size();
    unordered_map<int, vector<int>> val2idxMap;
    for (int i = 0; i < n; ++i)
      val2idxMap[A[i]].push_back(i);
    vector<bool> visit(n);
    visit[0] = true;
    queue<int> q;
    q.push(0);
    int step = 0;
    while (q.size()) {
      int m = q.size();
      while (m-- > 0) {
        int u = q.front(); q.pop();
        if (u == n - 1)
          return step;
        auto& neighbors = val2idxMap[A[u]];
        neighbors.push_back(u-1);
        neighbors.push_back(u+1);
        for (int v : neighbors) {
          if (v < 0 || v >= n || visit[v])
            continue;
          visit[v] = true;
          q.push(v);
        }
        neighbors.clear();
      }
      step++;
    }
    return 0;
  }
};
