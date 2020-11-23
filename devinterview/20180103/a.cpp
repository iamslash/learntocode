// Copyright (C) 2018 by iamslash

// https://www.hackerrank.com/challenges/castle-on-the-grid/problem


#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

class Point {
 public:
  int x, y, d;
  Point(int _x, int _y, int _d = 0) : x(_x), y(_y), d(_d) { }
};

int N;

std::vector<Point> get_neighbors(const std::vector<std::string>& grid, const Point& p) {
  std::vector<Point> r;

  //  x, y
  //------
  //  0,-1 l-direction
  //  0, 1 r-direction
  // -1, 0 t-direction
  //  1, 0 b-direction

  int x = p.x;
  int y = p.y;

  while (y > 0) {
    y--;
    // printf(" l [%2d, %2d]\n", x, y);
    if (grid[x][y] == 'X')
      break;
    r.emplace_back(x, y, p.d + 1);
  }  

  y = p.y;
  while (y < N-1) {
    y++;
    // printf(" r [%2d, %2d]\n", x, y);
    if (grid[x][y] == 'X')
      break;
    r.emplace_back(x, y, p.d + 1);
  }

  y = p.y;
  while (x > 0) {
    x--;
    // printf(" t [%2d, %2d]\n", x, y);
    if (grid[x][y] == 'X')
      break;
    r.emplace_back(x, y, p.d + 1);
  }  

  x = p.x;
  while (x < N-1) {
    x++;
    // printf(" b [%2d, %2d]\n", x, y);
    if (grid[x][y] == 'X')
      break;
    r.emplace_back(x, y, p.d + 1);
  }
  
  return r;
}

int minimumMoves(const std::vector<std::string>& grid,
                 int startX, int startY, int goalX, int goalY) {
  // Complete this function
  int r = -1;

  std::vector<std::vector<int>> found(N, std::vector<int>(N, false));
  std::queue<Point> q;
  found[startX][startY] = true;
  q.push(Point(startX, startY));

  while (!q.empty() && r < 0) {
    Point here = q.front(); q.pop();
    std::vector<Point> neighbors = get_neighbors(grid, here);
    // printf("[%2d, %2d] %2d\n", here.x, here.y, neighbors.size()); 
    for (const auto& next : neighbors) {
      // end condition
      if (next.x == goalX && next.y == goalY) {
        r = next.d;
        break;
      }
      // else
      if (!found[next.x][next.y]) {
        found[next.x][next.y] = true;
        q.push(Point(next.x, next.y, next.d));
      }
    }
  }

  return r;
  
}

int main() {
    cin >> N;
    vector<string> grid(N);
    for(int grid_i = 0; grid_i < N; grid_i++){
       cin >> grid[grid_i];
    }
    int startX;
    int startY;
    int goalX;
    int goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(grid, startX, startY, goalX, goalY);
    printf("%d\n", result);
    return 0;
}
