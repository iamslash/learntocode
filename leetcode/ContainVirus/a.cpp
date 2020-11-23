/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <set>

// 000 001 normal
// 000 011 infected
// 000 111 after install wall
class Solution {
 private:
  int m_h;
  int m_w;
  std::vector<std::vector<int>> m_G;
  std::set<std::pair<std::pair<int,int>,std::pair<int,int>>> m_wall;
  void installWall(int y, int x) {
    // printf("%d,%d\n", y, x);
    
    m_G[y][x] |= 0x04;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        for (int i = 0; i < 4; ++i) {          
          int ny = y + dy[i];
          int nx = x + dx[i];
          if (ny < 0 || ny >= m_h || nx < 0 || nx >= m_w)
            continue;
          if (m_G[ny][nx] == 0) {
            m_wall.insert({{y, x},{ny, nx}});
            continue;
          }
          if (m_G[ny][nx] & 0x04) {
            continue;
          }
          installWall(ny, nx);          
        }
      }
    }
  }
  void infectVirus(int y, int x) {
    m_G[y][x] |= 0x02;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        for (int i = 0; i < 4; ++i) {          
          int ny = y + dy[i];
          int nx = x + dx[i];
          if (ny < 0 || ny >= m_h || nx < 0 || nx >= m_w)
            continue;
          if (m_G[ny][nx] == 0) {
            m_G[ny][nx] = 0x03;
            continue;
          }
          if (m_G[ny][nx] & 0x02) {
            continue;
          }
          infectVirus(ny, nx);          
        }
      }
    }
  }
 public:
  int containVirus(std::vector<std::vector<int>>& G) {
    if (G.empty() || G[0].empty())
      return 0;
    m_h = G.size();
    m_w = G[0].size();
    m_G = G;
    bool binstalled = true;
    int day = 0;
    while (binstalled) {
      if (day > 0) {
        for (int y = 0; y < m_h; ++y) {
          for (int x = 0; x < m_w; ++x) {
            if ((G[y][x] & 0x02) == 0) {
              infectVirus(y, x);
            }
          }
        }
      }
      day++;
      binstalled = false;
      for (int y = 0; y < m_h; ++y) {
        for (int x = 0; x < m_w; ++x) {
          if (G[y][x] && ((G[y][x] & 0x04) == 0)) {
            installWall(y, x);
            binstalled = true;
          }
        }
      }
    }
    
    return m_wall.size();
  }
};

int main() {

  std::vector<std::vector<int>> G = {
    {0,1,0,0,0,0,0,1},
    {0,1,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}    
  };
  // std::vector<std::vector<int>> G = {
  //   {1,1,1},
  //   {1,0,1},
  //   {1,1,1}
  // };
  Solution sln;
  printf("%d\n", sln.containVirus(G));

  return 0;
}
