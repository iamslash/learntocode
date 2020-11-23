// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/PROMISES

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>

#define MAX_V 200
#define MAX_INT 987654321

int V, M, N;
int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];

void floyd() {
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        if (adj[i][j] > adj[i][k] + adj[k][j]) {
          via[i][j] = k;
          adj[i][j] = adj[i][k] + adj[k][j];
        }
      }
    }
  }
}

bool update(int a, int b, int c) {
  if (adj[a][b] <= c)
    return false;
  for (int x = 0; x < V; ++x) {
    for (int y = 0; y < V; ++y) {
      adj[x][y] =
          std::min(adj[x][y],
                   std::min(adj[x][a] + c + adj[b][x],
                            adj[x][b] + c + adj[a][x]));
    }
  }
  return true;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < MAX_V; ++i) {
      for (int j = 0; j < MAX_V; ++j) {
        if (i == j) {
          adj[i][j] = 0;
        } else {
          adj[i][j] = MAX_INT;
        }
        via[i][j] = -1;
      }
    }
    scanf("%d %d %d", &V, &M, &N);
    for (int i = 0; i < M; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      adj[a][b] = c;
      adj[b][a] = c;
    }
    floyd();
    int uselesscnt = 0;
    for (int i = 0; i < N; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      if (update(a, b, c) == false)
        ++uselesscnt;
    }
    printf("%d\n", uselesscnt);
  }
  return 0;
}
