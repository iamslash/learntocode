/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>

// [-1,-1,-1,-1,-1,-1],
// [-1,-1,-1,-1,-1,-1],
// [-1,-1,-1,-1,-1,-1],
// [-1,35,-1,-1,13,-1],
// [-1,-1,-1,-1,-1,-1],
// [-1,15,-1,-1,-1,-1]]

// 40ms 29.80% 17.1MB 13.71%
// BFS
// O(V+E) O(V)
class Solution {
 private:
  std::vector<int> getNextCoord(int nxt, int n) {
    int y = (nxt - 1) / n;
    int x = (nxt - 1) % n;
    if (y & 1)
      x = n - 1 - x;
    y = n - 1 - y;
    return {y, x};
  }
 public:
  int snakesAndLadders(std::vector<std::vector<int>>& B) {
    int n = B.size(), G = n * n;
    std::unordered_map<int, int> step;
    step[1] = 0;
    std::queue<int> q;
    q.push(1);
    while (q.size()) {
      int cur = q.front(); q.pop();
      if (cur == G)
        return step[cur];
      for (int i = 1; i <= 6; ++i) {
        int nxt = cur + i;
        if (nxt > G)
          break;
        auto v = getNextCoord(nxt, n);
        int vy = v[0], vx = v[1];
        if (B[vy][vx] != -1)
          nxt = B[vy][vx];
        if (!step.count(nxt)) {
          step[nxt] = step[cur] + 1;
          q.push(nxt);
        }
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
