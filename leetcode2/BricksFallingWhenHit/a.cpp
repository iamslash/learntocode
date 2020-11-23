/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
// 1 0 0 0
// 1 1 0 0

// // Time Limit Exceeded
// // DFS
// class Solution {
//  private:
//   vector<int> dir = {-1, 0, 1, 0, -1};
//   vector<vector<int>> G;
//   vector<vector<int>> visit;
//   int id;
//   int h, w;
//   bool falling(int y, int x) {
//     if (invalid(y, x))
//       return true;
//     if (visit[y][x] == id)
//       return true;
//     if (y == 0)
//       return false;
//     visit[y][x] = id;
//     for (int i = 0; i < 4; ++i) {
//       if (!falling(y + dir[i], x + dir[i+1]))
//         return false;
//     }
//     return true;
//   }
//   int cnt(int y, int x) {
//     if (invalid(y, x))
//       return 0;
//     int ans = 1;
//     G[y][x] = 0;
//     for (int i = 0; i < 4; ++i) {
//       ans += cnt(y + dir[i], x + dir[i+1]);
//     }
//     return ans;
//   }
//   bool invalid(int y, int x) {
//     return y < 0 || y >= h || x < 0 || x >= w || G[y][x] == 0;
//   }
//  public:
//   vector<int> hitBricks(vector<vector<int>>& grid,
//                         vector<vector<int>>& hits) {
//     h = grid.size(), w = grid[0].size();
//       // printf("y: %d, x: %d\n", h, w);
//     G.swap(grid);
//     visit.resize(201, vector<int>(201));
//     vector<int> ans;
//     for (auto hit : hits) {
//       int y = hit[0], x = hit[1];
//       int removed = 0;

//       if (G[y][x] == 1) {
//         G[y][x] = 0;
//         for (int i = 0; i < 4; ++i) {
//           int ny = y + dir[i];
//           int nx = x + dir[i+1];
//           if (invalid(ny, nx))
//             continue;
//           ++id;
//           if (falling(ny, nx))
//             removed += cnt(ny, nx);
//         }
//       }
//       ans.push_back(removed);
//     }
//     return ans;
//   }
// };

// 196ms 96.77% 35.5MB 74.91%
// DFS
class Solution {
 private:
  int h, w;
  int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  int dfs(vector<vector<int>>& G, int y, int x) {
    G[y][x] = 2;
    int cnt = 1;
        
    for(int d = 0; d < 4; d++) {
      int ny = y + dir[d][0], nx = x + dir[d][1];            
      if (ny < 0 || ny >= h || nx < 0 ||
          nx >= w || G[ny][nx] != 1)
        continue;            
      cnt += dfs(G, ny, nx);
    }
    return cnt;
  }
 public:
  vector<int> hitBricks(vector<vector<int>>& G, vector<vector<int>>& H) {
    h = G.size();
    w = G[0].size();
    for(auto& hit : H) {
      int y = hit[0], x = hit[1];
      if (G[y][x] == 1) {
        G[y][x] = -1;
      } else {
        G[y][x] = -2;
      }
    }        
    for(int x = 0; x < w; x++) {
      if (G[0][x] == 1) {
        dfs(G, 0, x);
      }
    }
    vector<int> ans;
    getNumHitBricks(G, H, ans);
    reverse(ans.begin(), ans.end());
    return ans;
  }
    
  void getNumHitBricks(vector<vector<int>>& G, const vector<vector<int>>& H, vector<int>& ans) {        
    int length = H.size();
    int count;
        
    for(int i = length - 1; i >= 0; i--) {
      int y = H[i][0], x = H[i][1];
      count = 0;
      if (G[y][x] == -2) {
        G[y][x] = 0;
      } else {
        G[y][x] = 1;
        for(int d = 0; d < 4; d++) {
          int ny = y + dir[d][0], nx = x + dir[d][1];
          if (y != 0 && (ny < 0 || ny >= h || 
                         nx < 0 || nx >= w ||
                         G[ny][nx] != 2))
            continue;                    
          count = dfs(G, y, x) - 1;
          break;
        }
      }
      ans.push_back(count);
    }
  }
    
};
