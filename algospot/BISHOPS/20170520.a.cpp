// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/BISHOPS

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

int N;
std::vector<std::string> BOARD;

// variables for PlaceBishops
const int dx[2] = {-1, 1};
const int dy[2] = {1, 1};
int id[2][8][8];
int adj[64][64];

// variables for BipartiteMatch
int L, R;
std::vector<int> a_match;
std::vector<int> b_match;
std::vector<bool> visited;

bool Dfs(int a) {
  if (visited[a])
    return false;
  visited[a] = true;
  for (int b = 0; b < R; ++b) {
    if (adj[a][b]) {
      if (b_match[b] == -1 || Dfs(b_match[b])) {
        a_match[a] = b;
        b_match[b] = a;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatch() {
  a_match = std::vector<int>(L, -1);
  b_match = std::vector<int>(R, -1);
  int r = 0;
  for (int start = 0; start < L; ++start) {
    visited = std::vector<bool>(L, false);
    if (Dfs(start))
      ++r;
  }
  return r;
}

int PlaceBishops() {
  memset(id, -1, sizeof(id));
  int count[2] = {0, };
  for (int dir = 0; dir < 2; ++dir) {
    for (int y = 0; y < BOARD.size(); ++y) {
      for (int x = 0; x < BOARD.size(); ++x) {
        if (BOARD[y][x] == '.' && id[dir][y][x] == -1) {
          int cy = y;
          int cx = x;
          while (0 <= cy && cy < BOARD.size() &&
                 0 <= cx && cx < BOARD.size() &&
                 BOARD[cy][cx] == '.') {
            id[dir][cy][cx] = count[dir];
            cy += dy[dir];
            cx += dx[dir];
          }
          count[dir]++;
        }
      }
    }
  }
  // make bipartite graph
  L = count[0];
  R = count[1];
  memset(adj, 0, sizeof(adj));
  for (int y = 0; y < BOARD.size(); ++y) {
    for (int x = 0; x < BOARD.size(); ++x) {
      if (BOARD[y][x] == '.') {
        adj[id[0][y][x]][id[1][y][x]] = 1;
      }
    }
  }

  return BipartiteMatch();
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    BOARD.clear();
    for (int i = 0; i < N; ++i) {
      char buf[12] = {0, };
      scanf("%s", buf);
      BOARD.push_back(buf);
    }
    printf("%d\n", PlaceBishops());
  }
}
