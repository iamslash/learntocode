// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>

#define MAX_INT 987654321
#define MAX_V 6

int V = MAX_V;

int adj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i)
    printf("%d ", v[i]);
  printf("\n");
}

void floyd() {
  for (int i = 0; i < V; ++i)
    adj[i][i] = 0;
  memset(via, -1, sizeof(via));
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

void reconstruct(int u, int v, std::vector<int>& path) {
  if (via[u][v] == -1) {
    path.push_back(u);
    if (u != v)
      path.push_back(v);
  } else {
    int w = via[u][v];
    reconstruct(u, w, path);
    path.pop_back();
    reconstruct(w, v, path);
  }
}

int main() {
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      adj[i][j] = MAX_INT;
    }
  }
  // for (int i = 0; i < V; ++i) {
  //   for (int j = 0; j < V; ++j) {
  //     printf("%d ", adj[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("%d\n", sizeof(adj));

  adj[0][1] = 10;
  adj[0][5] = 8;
  adj[1][3] = 2;
  adj[2][1] = 1;
  adj[3][2] = -2;
  adj[4][1] = 2;
  adj[4][3] = -1;
  adj[5][4] = 1;

  floyd();
  
  std::vector<int> r;
  reconstruct(0, 5, r);
  PrintVInt(r);
  
  return 0;
}
