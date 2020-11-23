/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <numeric>

// // 840ms 7.41% 10.1MB 100.00%
// // DFS
// class Solution {
//  private:
//   int m_cnt;
//   int m_bst;
//   void solve(std::vector<std::vector<int>>& G, int y, int x) {
//     // base
//     G[y][x] += 2;
//     m_cnt++;

//     // recursion
//     int dy[4] = {-1, 0, 1, 0};
//     int dx[4] = {0, 1, 0, -1};
//     for (int i = 0; i < 4; ++i) {
//       int ny = y + dy[i];
//       int nx = x + dx[i];
//       if (ny < 0 || ny >= G.size() || nx < 0 || nx >= G[0].size() ||
//           G[ny][nx] != 1)
//         continue;
//       solve(G, ny, nx);
//     }
//   }
//   void init(std::vector<std::vector<int>>& G) {
//     for (int y = 0; y < G.size(); ++y) {
//       for (int x = 0; x < G[0].size(); ++x) {
//         G[y][x] = G[y][x] >= 2 ? G[y][x] - 2 : G[y][x];
//       }
//     }
//   }
//  public:
//   int largestIsland(std::vector<std::vector<int>>& G) {
//     m_bst = 0;
//     m_cnt = 0;
//     if (G.empty() || G[0].empty())
//         return m_bst;
//     bool b_all_one = true;
//     for (int y = 0; y < G.size(); ++y) {
//       for (int x = 0; x < G[0].size(); ++x) {
//         if (G[y][x] == 0)
//           b_all_one = false;
//       }
//     }
//     if (b_all_one)
//       return G.size() * G[0].size();
//     // dfs
//     for (int y = 0; y < G.size(); ++y) {
//       for (int x = 0; x < G[0].size(); ++x) {
//         if (G[y][x] == 0) {
//           solve(G, y, x);          
//           m_bst = std::max(m_bst, m_cnt);
//           m_cnt = 0;
//           init(G);
//         }
//       }
//     }
//     return m_bst;
//   }
// };

// 36ms 49.23%
// DFS
// O(HW) O(C)
class Solution {
 private:
  int get(std::vector<std::vector<int>>& G, int y, int x) {
    return (y < 0 || y >= G.size() || x < 0 || x >= G[0].size()) ? 0 : G[y][x];
  }
  int paint(std::vector<std::vector<int>>& G, int y, int x, int c) {
    if (get(G, y, x) != 1)
      return 0;
    G[y][x] = c;
    return 1 +
        paint(G, y-1, x, c) +
        paint(G, y, x+1, c) +
        paint(G, y+1, x, c) +
        paint(G, y, x-1, c);        
  }
 public:
  int largestIsland(std::vector<std::vector<int>>& G) {
    if (G.empty() || G[0].empty())
      return 0;
    int h = G.size();
    int w = G[0].size();
    std::vector<int> c2s = {0, 0};  // color 2 space
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 1)
          c2s.push_back(paint(G, y, x, c2s.size()));
      }
    }
    // printf("%d\n", c2s.size());
    int rslt = 0;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 0) {
          std::unordered_set<int> idx = {get(G,y-1,x), get(G,y,x+1),
                                         get(G,y+1,x), get(G,y,x-1)};
          int island = 1;
          for (int i : idx)
            island += c2s[i];
          rslt = std::max(rslt, island);
        }
      }
    }
    return rslt == 0 ? h*w : rslt;
  }
};

int main() {

  // std::vector<std::vector<int>> G = {
  //   {1, 0},
  //   {0, 1}};
  std::vector<std::vector<int>> G = {
    {1, 1},
    {1, 0}};
  // std::vector<std::vector<int>> G = {
  //   {1, 1},
  //   {1, 1}};

  Solution sln;
  printf("%d\n", sln.largestIsland(G));
  
  return 0;
}
