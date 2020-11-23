/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <limits>
#include <set>

// 
// openset, closeset
// f = g + h

struct cell {
  int m_p_y; // parent y
  int m_p_x; // parent x
  double m_f;
  double m_g;
  double m_h;
};

class Solution {
 private:
  std::vector<std::vector<int>> m_G;
  std::vector<std::vector<cell>> m_C;
  int m_h;
  int m_w;
  int m_ys;  // y of src 
  int m_xs;  // x of src
  int m_yd;  // y of dst
  int m_xd;  // x of dst
 private:
  bool is_valid(int y, int x) {
    return y >= 0 && y < m_h && x >= 0 && x < m_w;                         
  }
  bool is_placeable(int y, int x) {
    return m_G[y][x] == 1;
  }
  bool is_dst(int y, int x) {
    return y == m_yd && x == m_xd;
  }
  double get_h(int y, int x) {
    return std::sqrt(std::pow(y - m_yd, 2) + std::pow(x - m_xd, 2));
  }
  std::vector<std::pair<int, int>> get_path() {
    std::vector<std::pair<int, int>> path;
    int y = m_yd;
    int x = m_xd;
    // printf("(y:%d, x:%d) (m_ys:%d, m_xs:%d) (m_yd:%d, m_xd:%d)\n",
    //        y, x, m_ys, m_xs, m_yd, m_xd);
    while (y != m_ys || x != m_xs) {
      path.push_back({y, x});
      cell& C = m_C[y][x];
      y = C.m_p_y;
      x = C.m_p_x;
    }
    path.push_back({y, x});
    std::reverse(path.begin(), path.end());
    return path;
  }  
 public:
  std::vector<std::pair<int, int>> solve_astar(std::vector<std::vector<int>>& G,
                   int ys, int xs, int yd, int xd) {
    m_G = G;
    m_h = G.size();
    m_w = G[0].size();
    m_ys = ys;
    m_xs = xs;
    m_yd = yd;
    m_xd = xd;

    // open set, close set
    std::set<std::pair<double, std::pair<int, int>>> st_open;
    std::set<std::pair<int, int>> st_close;

    // cell
    m_C.resize(m_h, std::vector<cell>(m_w));
    for (int y = 0; y < m_h; ++y) {
      for (int x = 0; x < m_w; ++x) {
        cell& C = m_C[y][x];
        if (y == ys && x == xs) {
          C.m_f = 0.0;
          C.m_g = 0.0;
          C.m_h = 0.0;
          C.m_p_y = y;
          C.m_p_x = x;
          st_open.insert({C.m_f, {y, x}});
        } else {
          C.m_f = std::numeric_limits<double>::max();
          C.m_g = std::numeric_limits<double>::max();
          C.m_h = std::numeric_limits<double>::max();
          C.m_p_y = -1;
          C.m_p_x = -1;
        }
      }
    }

    int dy[8] = {-1, 1, 0, 1, 1,  1,  0, -1};
    int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
    
    while (!st_open.empty()) {
      // get node which has small f
      auto it = st_open.begin();
      int y = (*it).second.first;
      int x = (*it).second.second;
      st_open.erase(it);
      st_close.insert({y, x});

      if (is_dst(y, x)) {
        // printf("st_open.count: %d, st_close.count: %d\n",
        //        st_open.size(), st_close.size());
        return get_path();
      }
      
      for (int d = 0; d < 8; ++d) {
        // get node to visit
        int yn = y + dy[d];
        int xn = x + dx[d];

        // printf("  %d, %d\n", yn, xn);
        
        if (!is_valid(yn, xn) ||
            st_close.count({yn, xn}) > 0 ||
            !is_placeable(yn, xn))
          continue;
        
        cell& C = m_C[yn][xn];
        double gn = C.m_g + 1.0;
        double hn = get_h(yn, xn);
        double fn = gn + hn;
        if (C.m_f == std::numeric_limits<double>::max() ||
            C.m_f > fn) {
          st_open.insert({fn, {yn, xn}});
          C.m_f = fn;
          C.m_g = gn;
          C.m_h = hn;
          C.m_p_y = y;
          C.m_p_x = x;
          // printf("(%d, %d) -> (%d, %d)\n", y, x, yn, xn);          
        }
      }
    }

    return {};
  }
};

int main() 
{
  //  0: obstacle, 1: road
  std::vector<std::vector<int>> G = 
      { 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } 
      }; 
  Solution sln;
  auto path = sln.solve_astar(G, 8, 0, 0, 0);

  for (const auto& pr : path)
    printf("[%d, %d]\n", pr.first, pr.second);
  
  return(0); 
}
