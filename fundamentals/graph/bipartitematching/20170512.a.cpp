// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

const int MAX_V = 3;

int L, R;
bool adj[MAX_V][MAX_V];
std::vector<int> a_match;
std::vector<int> b_match;
std::vector<bool> visited;

bool Dfs(int a) {
  if (visited[a])
    return false;
  visited[a] = true;
  for (int b = 0; b < R; ++b) {
    if (adj[a][b]) {
      printf("  %d : %d\n", a, b);
      if (b_match[b] == -1 || Dfs(b_match[b])) {
        printf("    %d -> %d\n", a, b);

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
    printf("start: %d\n", start);
    visited = std::vector<bool>(L, false);
    if (Dfs(start))
      ++r;
  }
  return r;
}

int main() {
  L = 3;
  R = 3;
  for (int i = 0; i < MAX_V; ++i) {
    for (int j = 0; j < MAX_V; ++j) {
      adj[i][j] = false;
    }
  }
  adj[0][1] = true;
  adj[0][2] = true;
  adj[1][1] = true;
  // adj[2][0] = true;

  printf("%d\n", BipartiteMatch());
}
