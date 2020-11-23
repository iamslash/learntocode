// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>

int N = 4;

std::vector<std::vector<int>> adj;
std::vector<int> discovered, finished;
int counter = 0;
bool bcycle = false;

void dfs_spanning_tree(int u) {
  // base
  if (bcycle)
    return;

  // recursion
  discovered[u] = ++counter;
  for (int v = 0; v < adj[u].size(); ++v) {
    if (adj[u][v] == 0)
      continue;
    if (discovered[v] < 0) {  // tree edge
      // printf("%d-%d : tree\n", u, v);
      dfs_spanning_tree(v);
    } else if (discovered[u] < discovered[v]) {  // forward edge
      // printf("%d-%d : forward\n", u, v);
    } else if (finished[v] == 0) {
      // printf("%d-%d : backward\n", u, v);
      bcycle = true;
    } else {
      // printf("%d-%d : cross\n", u, v);
    }
  }
  finished[u] = 1;
}

int main() {
  adj = std::vector<std::vector<int> >(N, std::vector<int>(N, 0));
  adj[0][1] = 1;
  adj[0][2] = 1;
  adj[0][3] = 1;
  adj[1][2] = 1;
  adj[2][1] = 1;
  adj[3][1] = 1;
  adj[3][2] = 1;
  discovered = std::vector<int>(N, -1);
  finished = std::vector<int>(N, 0);
  dfs_spanning_tree(0);
  printf("%s\n", bcycle ? "true" : "false");
  return 0;
}
