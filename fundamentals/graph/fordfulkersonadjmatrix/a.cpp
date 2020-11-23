// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

const int MAX_V = 4;
const int MAX_I = 987654321;
int V = MAX_V;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int ford_fulkerson(int src, int snk) {
  int rslt = 0;
  for (int i = 0; i < MAX_V; ++i) {
    for (int j = 0; j < MAX_V; ++j) {
      flow[i][j] = 0;
    }
  }
  while (true) {
    std::vector<int> parent(MAX_V, -1);
    std::queue<int> q;
    parent[src] = src;
    q.push(src);
    while (!q.empty()) {
      // find a augmenting path
      int u = q.front(); q.pop();
      for (int v = 0; v < V; ++v) {
        if (capacity[u][v] - flow[u][v] > 0
            && parent[v] == -1) {
          q.push(v);
          parent[v] = u;
        }
      }
    }
    if (parent[snk] == -1)
      break;

    // compute bottlenack capacity
    int amount = MAX_I;
    for (int v = snk; v != src; v = parent[v]) {
      int u = parent[v];
      amount = std::min(capacity[u][v] - flow[u][v], amount);
    }
    // augment each edge and the total flow
    for (int v = snk; v != src; v = parent[v]) {
      int u = parent[v];
      flow[u][v] += amount;
      flow[v][u] -= amount;
    }
    rslt += amount;
  }
  return rslt;
}

int main() {
  capacity[0][1] = 1;
  capacity[0][2] = 2;
  capacity[1][3] = 3;
  capacity[1][2] = 1;
  capacity[2][3] = 1;

  printf("%d\n", ford_fulkerson(0, 3));
}
