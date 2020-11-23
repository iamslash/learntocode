/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// 1 0 0
// 1 1 0
// 1 1 0

// // 52ms 79.60% 14MB 100.00%
// // BFS
// // O(N) O(N)
// class Solution {
//  public:
//   int shortestPathBinaryMatrix(std::vector<std::vector<int>>& G) {
//     int h = G.size(), w = G[0].size();
//     if (G[0][0] || G[h-1][w-1])
//       return -1;
//     int delta[10] = {-1, -1, 0, 1, 1, 1, 0, -1, -1, -1};
//     std::queue<std::pair<int, int>> q;
//     q.push({0, 1});
//     G[0][0] = 2;
//     while (q.size()) {
//       auto pr = q.front(); q.pop();
//       int y = pr.first / 100;
//       int x = pr.first % 100;
//       int d = pr.second;
//       if (y == h-1 && x == w - 1)
//         return d;
//       for (int i = 0; i < 8; ++i) {
//         int ny = y + delta[i];
//         int nx = x + delta[i+2];
//         int nd = d + 1;
//         if (ny < 0 || ny >= h || nx < 0 || nx >= w || G[ny][nx])
//           continue;
//         G[ny][nx] = 2;
//         q.push({ny * 100 + nx, nd});
//       }
//     }
//     return -1;
//   }
// };


// 48ms 91.83% 13MB 100.00%
class Solution {
 public:
  int shortestPathBinaryMatrix(std::vector<std::vector<int>>& G) {
    int h = G.size(), w = G[0].size();
    if (G[0][0] || G[h-1][w-1])
      return -1;
    int delta[10] = {-1, -1, 0, 1, 1, 1, 0, -1, -1, -1};
    int ans = 0;
    std::queue<int> q;
    q.push(0);
    G[0][0] = 2;
    while (q.size()) {
      ans++;
      int qsize = q.size();
      for (int j = 0; j < qsize; ++j) {
        int t = q.front(); q.pop();
        int y = t / 100;
        int x = t % 100;
        if (y == h-1 && x == w - 1)
          return ans;
        for (int i = 0; i < 8; ++i) {
          int ny = y + delta[i];
          int nx = x + delta[i+2];
          if (ny < 0 || ny >= h || nx < 0 || nx >= w || G[ny][nx])
            continue;
          G[ny][nx] = 2;
          q.push(ny * 100 + nx);
        }
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
