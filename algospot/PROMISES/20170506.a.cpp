// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/TIMETRIP

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>

#define MAX_V 300
#define MAX_I 987654321

int N, M;
int profit[100];
int cost[100];

int V;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];
int adj[MAX_V][MAX_V];

int FordFulkerson(int source, int sink) {
  int r = 0;

  while (true) {
    std::vector<int> parent(V, -1);
    std::queue<int> q;
    parent[source] = source;
    q.push(source);
    while (!q.empty() && parent[sink] == -1) {
      int here = q.front();
      q.pop();
      for (int there = 0; there < V; ++there) {
        if (capacity[here][there] - flow[here][there] &&
            parent[there] == -1) {
          q.push(there);
          parent[there] = here;
        }
      }
    }
    // terminate if there is no augmenting path
    if (parent[sink] == -1)
      break;
    int amount = MAX_I;
    for (int p = sink; p != source; p = parent[p]) {
      amount = std::min(amount,
                        capacity[parent[p]][p] - flow[parent[p]][p]);
    }
    for (int p = sink; p != source; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }
    r += amount;
  }
  return r;
}

int MaxProfit() {
  const int source = 0;
  const int sink = 1;

  for (int i = 0; i < N; ++i) {
    capacity[source][2 + i] = profit[i];
  }
  for (int i = 0; i < M; ++i) {
    capacity[2 + N + i][sink] = cost[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (adj[i][j]) {
        capacity[2 + i][2 + N + j] = MAX_I;
      }
    }
  }
  int M = std::accumulate(profit, profit + N, 0);
  int C = FordFulkerson(source, sink);

  return M - C;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    V = 2 + N + M;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &profit[i]);
    }
    for (int i = 0; i < M; ++i) {
      scanf("%d", &cost[i]);
    }

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        scanf("%d", &adj[i][j]);
      }
    }

    for (int i = 0; i < MAX_V; ++i) {
      for (int j = 0; j < MAX_V; ++j) {
        capacity[i][j] = 0;
        flow[i][j] = 0;
      }
    }

    printf("%d\n", MaxProfit());
  }
  return 0;
}
