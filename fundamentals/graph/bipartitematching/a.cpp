// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

const int MAX_V = 3;

int L, R;
bool adj[MAX_V][MAX_V];
std::vector<int> amatch;
std::vector<int> bmatch;
std::vector<bool> visited;

bool dfs(int u) {
  if (visited[u])
    return false;
  visited[u] = true;
  for (int v = 0; v < R; ++v) {
    if (adj[u][v]) {
      if (bmatch[v] == -1 || dfs(bmatch[v])) {
        amatch[u] = v;
        bmatch[v] = u;
        return true;
      }
    }
  }
  return false;
}

int bipartite_match() {
  amatch = std::vector<int>(L, -1);
  bmatch = std::vector<int>(R, -1);
  int maxmatch = 0;
  for (int src = 0; src < L; ++src) {
    visited = std::vector<bool>(L, false);
    if (dfs(src))
      ++maxmatch;
  }
  return maxmatch;
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

  printf("%d\n", bipartite_match());
}
