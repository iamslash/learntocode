/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// // 44ms 66.67%
// // 10.1MB 0.00%
// // dijkstra
// // O(N^2lgN) O(N^2)
// class Solution {
//  public:
//   int swimInWater(std::vector<std::vector<int>>& G) {
//     int n = G.size();
//     int rslt = std::max(G[0][0], G[n-1][n-1]);
//     std::priority_queue<std::vector<int>,
//                         std::vector<std::vector<int>>,
//                         std::greater<std::vector<int>>> pq;
//     std::vector<std::vector<int>> visited(n, std::vector<int>(n, 0));
//     visited[0][0] = 1;
//     int dy[4] = {-1, 0, 1,  0};
//     int dx[4] = {0,  1, 0, -1};
//     pq.push({rslt, 0, 0});
//     while (!pq.empty()) {
//       auto item = pq.top(); pq.pop();
//       rslt = std::max(rslt, item[0]);
//       for (int i = 0; i < 4; ++i) {
//         int ny = item[1] + dy[i];
//         int nx = item[2] + dx[i];
//         if (ny < 0 || ny >= n || nx < 0 || nx >= n ||
//             visited[ny][nx] > 0)
//           continue;
//         if (ny == n-1 && nx == n-1)
//           return rslt;
//         pq.push({G[ny][nx], ny, nx});
//         visited[ny][nx] = 1;
//       }
//     }
//     return -1;
//   }
// };

// 16ms 100.00%
// 6.1MB 0.00%
// dijkstra
// O(N^2lgN) O(N^2)
class Solution {
 public:
  int swimInWater(std::vector<std::vector<int>>& G) {
    int n = G.size();
    std::priority_queue<std::pair<int, int>> pq; // {-time, y * N + x}
    pq.push({-G[0][0], 0});
    std::vector<int> visited(n*n, 0);
    int dy[4] = {-1, 0, 1,  0};
    int dx[4] = {0,  1, 0, -1};
    visited[0] = 1;
    while (!pq.empty()) {
      auto v = pq.top(); pq.pop();
      int t = -v.first;
      int y = v.second / n;
      int x = v.second % n;
      if (y == n - 1 && x == n - 1)
        return t;
      for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n ||
            visited[ny * n + nx] > 0)
          continue;
        visited[ny * n + nx] = 1;
        pq.push({-std::max(t, G[ny][nx]), ny * n + nx}); 
      }
    }
    return -1;
  }
};

int main() {

  // std::vector<std::vector<int>> G = {
  //   {0,2},
  //   {1,3}
  // };
  std::vector<std::vector<int>> G = {
    { 0, 1, 2, 3, 4},
    {24,23,22,21, 5},
    {12,13,14,15,16},
    {11,17,18,19,20},
    {10, 9, 8, 7, 6}
  };

  Solution sln;
  printf("%d\n", sln.swimInWater(G));
  
  return 0;
}
