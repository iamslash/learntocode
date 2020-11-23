/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/109/backtracking/797/

#include <cstdio>
#include <vector>
#include <string>

class Solution {
public:
  std::vector<std::vector<char>> B;
  bool _solve(int y, int x, std::string s, int d) {
    // base condition
    if (B[y][x] != s[d])
      return false;
    if (d+1 >= s.size())
      return true;

    // recursion
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, -1, 0, 1};
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      B[y][x] = ~B[y][x];

      if (ny >= 0 && ny < B.size() && nx >= 0 && nx < B[0].size()
          && B[ny][nx] > 0 && _solve(ny, nx, s, d+1))
        return true;

      B[y][x] = ~B[y][x];
    }   
    return false;
  }
  bool exist(std::vector<std::vector<char>>& b, std::string s) {
    if (b.size() == 0 || s.empty())
      return false;
    B = b;
    // DFS
    for (int i = 0; i < b.size(); ++i) {
      for (int j = 0; j < b[0].size(); ++j) {
        if (_solve(i, j, s, 0))
          return true;
      }
    }
    return false;    
  }
};

int main() {
  // std::string w = "ABCCED";
  // std::vector<std::vector<char>> b = {
  //   {'A', 'B', 'C', 'E'},
  //   {'S', 'F', 'C', 'S'},
  //   {'A', 'D', 'E', 'E'}
  // };
  std::string w = "a";
  std::vector<std::vector<char>> b = {
    {'a'}
  };
  // std::string w = "aaa";
  // std::vector<std::vector<char>> b = {
  //   {'a', 'a'}
  // };
  // std::string w = "AAB";
  // std::vector<std::vector<char>> b = {
  //   {'C', 'A', 'A'},
  //   {'A', 'A', 'A'},
  //   {'B', 'C', 'D'},
  // };
  Solution s;
  printf("%s\n", s.exist(b, w) ? "true" : "false");  
  return 0;
}
