/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;


//  F: 1 2 3
//     0 0 4
//     7 6 5
// pq: (0,1,2) (0,2,3) (1,2,4) (2,2,5) (2,1,6) (2,0,7)
//  q: (2,0)

// // Time Limit Excceded
// // BFS, priority_queue
// // O(H^2W^2) O(HW)
// class PqCmp {
//  public:
//   bool operator()(const vector<int>& a, const vector<int>& b) {
//     return a[2] > b[2];
//   }
// };
// class Solution {
//  private:
//   int minStep(vector<vector<int>>& F, vector<int>& start, vector<int>& tree,
//               int h, int w) {
//     if (start[0] == tree[0] && start[1] == tree[1])
//       return 0;
//     int dir[5] = {-1, 0, 1, 0, -1};
//     int step = 0;
//     vector<vector<int>> visit(h, vector<int>(w, false));
//     queue<vector<int>> q;
//     q.push(start);
//     visit[start[0]][start[1]] = true;
//     while (q.size()) {
//       int n = q.size();
//       for (int i = 0; i < n; ++i) {
//         auto u = q.front(); q.pop();
//         if (u[0] == tree[0] && u[1] == tree[1])
//           return step;
//         for (int j = 0; j < 4; ++j) {
//           int ny = u[0] + dir[j];
//           int nx = u[1] + dir[j+1];
//           if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
//               F[ny][nx] == 0 || visit[ny][nx])
//             continue;
//           q.push({ny, nx});
//           visit[ny][nx] = true;
//         }
//       }
//       step++;
//     }
//     return -1;
//   }
//  public:
//   int cutOffTree(vector<vector<int>>& F) {
//     int h = F.size(), w = F[0].size();
//     if (h == 0 || w == 0)
//       return 0;
//     priority_queue<vector<int>, vector<vector<int>>, PqCmp> pq;
//     for (int y = 0; y < h; ++y) {
//       for (int x = 0; x < w; ++x) {
//         if (F[y][x] > 1) {
//           pq.push({y, x, F[y][x]});
//         }
//       }
//     }
//     vector<int> start(2, 0);
//     int ans = 0;
//     while (pq.size()) {
//       auto tree = pq.top(); pq.pop();
//       int step = minStep(F, start, tree, h, w);
//       if (step < 0)
//         return -1;
//       ans += step;
//       start[0] = tree[0];
//       start[1] = tree[1];
//     }
//     return ans;
//   }
// };


// pair<int> is fater than vector<int>
// 728ms 88.34% 151.6MB 40.38%
// BFS, sort
// O(H^2W^2) O(HW)
class Solution {
 private:
  int minStep(vector<vector<int>>& F, int beg_y, int beg_x, int end_y, int end_x, int h, int w) {
    if (beg_y == end_y && beg_x == end_x)
      return 0;
    queue<pair<int, int>> q;
    q.push({beg_y, beg_x});
    vector<vector<int>> visit(h, vector<int>(w, 0));
    visit[beg_y][beg_x] = 1;
    int step = 0;
    int dir[5] = {-1, 0, 1, 0, -1};
    while (q.size()) {
      step++;
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        auto u = q.front(); q.pop();
        for (int j = 0; j < 4; ++j) {
          int ny = u.first + dir[j];
          int nx = u.second + dir[j+1];
          if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
              visit[ny][nx] == 1 || F[ny][nx] == 0)
            continue;
          if (ny == end_y && nx == end_x)
            return step;
          visit[ny][nx] = 1;
          q.push({ny, nx});
        }
      }
    }
    return -1;
  }
 public:
  int cutOffTree(vector<vector<int>>& F) {
    int h = F.size(), w = F[0].size();
    if (h == 0 || w == 0)
      return 0;
    vector<vector<int>> trees;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (F[y][x] > 1)
          trees.push_back({F[y][x], y, x});
      }
    }
    sort(trees.begin(), trees.end());
    int ans = 0;
    for (int i = 0, beg_y = 0, beg_x = 0; i < trees.size(); ++i) {
      int step = minStep(F, beg_y, beg_x, trees[i][1], trees[i][2], h, w);
      if (step < 0)
        return -1;
      ans += step;
      beg_y = trees[i][1];
      beg_x = trees[i][2];
    }
    return ans;
  }
};
