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
// id[dir][y][x] = dir방향 대각선을 따라 인접한 빈 칸 묶음들 중 (y,
// x)가 속한 묶음의 번호
int id[2][8][8];
int adj[64][64];

// variables for BipartiteMatch
int L, R;
std::vector<int> amatch;
std::vector<int> bmatch;
std::vector<bool> visited;

bool dfs(int a) {
  if (visited[a])
    return false;
  visited[a] = true;
  for (int b = 0; b < R; ++b) {
    if (adj[a][b]) {
      if (bmatch[b] == -1 || dfs(bmatch[b])) {
        amatch[a] = b;
        bmatch[b] = a;
        return true;
      }
    }
  }
  return false;
}

int bipartite_match() {
  amatch = std::vector<int>(L, -1);
  bmatch = std::vector<int>(R, -1);
  int r = 0;
  for (int start = 0; start < L; ++start) {
    visited = std::vector<bool>(L, false);
    if (dfs(start))
      ++r;
  }
  return r;
}

int place_bishops() {
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

  return bipartite_match();
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
    printf("%d\n", place_bishops());
  }
}
