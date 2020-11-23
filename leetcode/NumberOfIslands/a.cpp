/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/792/

#include <cstdio>
#include <vector>

// N is count of cell
// O(N) O(1)
class Solution {
public:
  void _visit(std::vector<std::vector<char>>& g, int y, int x) {
    // base condition
    if (y < 0 || y >= g.size() ||
        x < 0 || x >= g[0].size() ||
        g[y][x] != '1')
      return;
    g[y][x] = '2';
    // visit neighbors    
    _visit(g, y-1, x);  // top    
    _visit(g, y+1, x);  // down
    _visit(g, y, x-1);// left
    _visit(g, y, x+1);// right
  }
  int numIslands(std::vector<std::vector<char>>& g) {
    if (g.size() == 0)
      return 0;
    int r = 0;
    for (int y = 0; y < g.size(); ++y) {
      for (int x = 0; x < g[y].size(); ++x) {
        // if is not visited yet.
        if (g[y][x] == '1') {
          _visit(g, y, x);
          r++;
        }
      }
    }
    return r;
  }
};

int main() {
  // std::vector<std::vector<char>> m = {{1,1,1,1,0},
  //                                     {1,1,0,1,0},
  //                                     {1,1,0,0,0},
  //                                     {0,0,0,0,0}};
  std::vector<std::vector<char>> m = {{'1','1','0','0','0'},
                                      {'1','1','0','0','0'},
                                      {'0','0','1','0','0'},
                                      {'0','0','0','1','1'}};
  Solution s;

  printf("%d\n", s.numIslands(m));
  return 0;
}
