// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/843/

#include <cstdio>
#include <vector>
#include <map>

class Solution {
 public:
  std::vector<std::vector<char>> m_B;  // board
  std::vector<std::vector<char>> m_V;  // visit
  std::vector<std::vector<std::pair<int, int>>> m_R;
  std::vector<std::pair<int, int>> m_C;  // combi
  bool m_surrounded;
  void dfs(int y, int x) {
    m_V[y][x] = 1;
    m_C.push_back(std::make_pair(y, x));
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || ny >= m_B.size() ||
          nx < 0 || nx >= m_B[0].size()) {
        m_surrounded = true;
        continue;
      } else if (m_B[ny][nx] == 'X' || m_V[ny][nx] > 0) {
        continue;
      }
      dfs(ny, nx);
    }
  }
  void solve(std::vector<std::vector<char>>& B) {
    if (B.empty() || B[0].empty())
      return;
    m_B = B;
    m_V = B;
    for (int i = 0; i < B.size(); ++i) {
      for (int j = 0; j < B[i].size(); ++j) {
        m_V[i][j] = 0;
      }
    }
    m_C.clear();
    m_surrounded = false;
    for (int y = 0; y < B.size(); ++y) {
      for (int x = 0; x < B[y].size(); ++x) {
        if (m_B[y][x] == 'X' || m_V[y][x] > 0)
          continue;
        dfs(y, x);
        if (m_surrounded == false) {
          m_R.push_back(m_C);
        }
        m_surrounded = false;
        m_C.clear();
        // printf("-----\n");
      }
    }
    for (const auto& r : m_R) {
      for (const auto& rr : r) {
        m_B[rr.first][rr.second] = 'X';
      }
    }
    B = m_B;
    return;
  }
};

int main() {
  std::vector<std::vector<char>> B = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'X'}
  };
  Solution s;
  s.solve(B);

  for (const auto& b : B) {
    for (char c : b) {
      printf("%c ", c);
    }
    printf("\n");
  }
  return 0;
}
