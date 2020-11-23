// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/BISHOPS

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>

int H, W;
std::vector<std::string> BOARD;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
std::vector<std::vector<int> > id;

std::vector<bool> a_chosen;
std::vector<bool> b_chosen;

int L, R;
std::vector<int> a_match;
std::vector<int> b_match;
std::vector<bool> visited;
int adj[400][400];

bool InRange(int y, int x) {
  if ( y < 0 || y >= H || x < 0 || x >= W)
    return false;
  return true;
}

void Build() {
  id.clear();
  id.resize(H, std::vector<int>(W, -1));
  L = 0;
  R = 0;
  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (BOARD[y][x] != '#') {
        if ((y + x) % 2 == 0) {
          id[y][x] = L++;
        } else {
          id[y][x] = R++;
        }
      }
    }
  }
  memset(adj, 0, sizeof(adj));

  for (int y1 = 0; y1 < H; ++y1) {
    for (int x1 = 0; x1 < W; ++x1) {
      if ((y1 + x1) % 2 == 0 && BOARD[y1][x1] != '#') {
        for (int k = 0; k < 4; ++k) {
          int y2 = y1 + dy[k];
          int x2 = x1 + dx[k];
          if (InRange(y2, x2) && BOARD[y2][x2] != '#') {
            adj[id[y1][x1]][id[y2][x2]] = 1;
          }
        }
      }
    }
  }
}

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

void CalcMaxIndependentSet() {
  int C = BipartiteMatch();

  a_chosen = std::vector<bool>(L, true);
  b_chosen = std::vector<bool>(R, false);
  for (int i = 0; i < R; ++i) {
    if (b_match[i] == -1)
      b_chosen[i] = true;
  }
  while (true) {
    bool changed = false;
    for (int i = 0; i < L; ++i) {
      for (int j = 0; j < R; ++j) {
        if (a_chosen[i] && b_chosen[j] && adj[i][j]) {
          assert(a_match[i] != -1);
          a_chosen[i] = false;
          b_chosen[a_match[i]] = true;
          changed = true;
        }
      }
    }
    if (!changed)
      break;
  }
}

void PrintResult() {
  int r = 0;
  for (int i = 0; i < a_chosen.size(); ++i) {
    if (a_chosen[i])
      ++r;
  }
  for (int i = 0; i < b_chosen.size(); ++i) {
    if (b_chosen[i])
      ++r;
  }
  printf("%d\n", r);

  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      if (BOARD[y][x] == '#') {
        printf("#");
      } else {
        if ((x + y) % 2 == 0) {
          printf("%c", a_chosen[id[y][x]] ? '^' : '.');
        } else {
          printf("%c", b_chosen[id[y][x]] ? '^' : '.');
        }
      }
    }
    printf("\n");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &H, &W);
    BOARD.clear();
    for (int i = 0; i < H; ++i) {
      char buf[24] = {0, };
      scanf("%s", buf);
      BOARD.push_back(buf);
    }
    Build();
    CalcMaxIndependentSet();
    PrintResult();
  }
}
