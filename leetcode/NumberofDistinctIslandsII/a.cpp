/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

void printv(std::vector<std::pair<int, int>>& v) {
  for (auto& pr : v)
    printf("(%d, %d) ", pr.first, pr.second);
  printf("\n");
}

// 140ms 69.89% 33.7MB 81.08%
// Q. what is the range of G.size(), G[0].size()? <= 50
// O(HWlg(HW)) O(HW)
class Solution {
 private:
  void dfs(std::vector<std::vector<int>>& G,
           int y, int x, std::vector<std::pair<int, int>>& path) {
    int h = G.size();
    int w = G[0].size();
    int ds[5] = {-1, 0, 1, 0, -1};
    path.push_back({y, x});
    G[y][x] = 0;
    for (int i = 0; i < 4; ++i) {
      int ny = y + ds[i];
      int nx = x + ds[i+1];
      if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
          G[ny][nx] == 0)
        continue;
      dfs(G, ny, nx, path);
    }
  }
  std::string normalize(std::vector<std::pair<int, int>>& path) {
    std::vector<std::vector<std::pair<int, int>>> P(8);
    for (auto& pr : path) {
      int x = pr.second;
      int y = pr.first;
      P[0].push_back({ x,  y});
      P[1].push_back({-x,  y});
      P[2].push_back({ x, -y});
      P[3].push_back({-x, -y});
      P[4].push_back({ y,  x});
      P[5].push_back({-y,  x});
      P[6].push_back({ y, -x});
      P[7].push_back({-y, -x});
    }
    for (auto& l : P)
      std::sort(l.begin(), l.end());
    for (auto& l : P) {
      int ox = l[0].first;
      int oy = l[0].second;
      for (int i = 0; i < l.size(); ++i) {
        l[i].first = l[i].first - ox;
        l[i].second = l[i].second - oy;
      }
    }
    std::sort(P.begin(), P.end());
    std::string s;
    for (auto& pr : P[0])
      s += '(' + std::to_string(pr.first) + ',' + std::to_string(pr.second) + ')';
    return s;
  }
 public:
  int numDistinctIslands2(std::vector<std::vector<int>>& G) {
    if (G.empty() || G[0].empty())
      return 0;
    int h = G.size();
    int w = G[0].size();
    std::unordered_set<std::string> ust;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (G[y][x] == 0)
          continue;
        std::vector<std::pair<int, int>> path;
        dfs(G, y, x, path);
        auto s = normalize(path);
        ust.insert(s);
        // printv(path);
        // printf("%s\n", s.c_str());
      }
    }
    return ust.size();
  }
};

int main() {

  // std::vector<std::vector<int>> G = {
  //   {11000},
  //   {10000},
  //   {00001},
  //   {00011}
  // };
  std::vector<std::vector<int>> G = {
    {1,1,1,0,0},
    {1,0,0,0,1},
    {0,2,0,0,1},
    {0,1,1,1,0}
  };

  Solution sln;
  printf("%d\n", sln.numDistinctIslands2(G));
  
  return 0;
}
