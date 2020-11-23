// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/DRUNKEN

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_V 500
#define MAX_I 987654321

int V, E;
int adj[MAX_V][MAX_V];
int delay[MAX_V];
int W[MAX_V][MAX_V];

void floyd() {
  st::vector<std::pair<int, int> > order;
  for (int i = 0; i < V; ++i)
    order.push_back(std::make_pair(delay[i], i));
  std::sort(order.begin(), order.end());
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      if (i == j)
        W[i][j] = 0;
      else
        W[i][j] = adj[i][j];
    }
  }
  int r = MAX_I;
  for (int k = 0; k < V; ++k) {
    int w = order[k].second;
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        adj[i][j] = std::min(adj[i][j], adj[i][w] + adj[w][j]);
        W[i][j] = std::min(W[i][j],
                           adj[i][w] + delay[w] +
                           adj[w][j]);
      }
    }
  }
}

int main() {
  scanf("%d %d", &V, &E);
  for (int i = 0; i < MAX_V; ++i)
    for (int j = 0; j < MAX_V; ++j)
      adj[i][j] = MAX_I;
  for (int i = 0; i < V; ++i) {
    scanf("%d", &delay[i]);
  }
  for (int i = 0; i < E; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    adj[a][b] = c;
    adj[b][a] = c;
  }

  floyd();

  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", W[a][b]);
  }
  return 0;
}
