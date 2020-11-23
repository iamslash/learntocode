// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/MATCHFIX

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>

#define MAX_V 200
#define MAX_I 987654321

int N, M;
std::vector<int> profit;
std::vector<int> cost;
int requires[MAX_V][MAX_V];

int V;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];


int ford_fulkerson(int source, int sink) {
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
      amount = std::min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
    }
    for (int p = sink; p != source; p = parent[p]) {
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }
    r += amount;
  }

  return r;
}


int solve() {
  const int src = 0;
  const int snk = 1;
  V = 2 + N + M;
  for (int i = 0; i < N; ++i) {
    capacity[src][2 + i] = profit[i];
  }
  for (int i = 0; i < M; ++i) {
    capacity[2 + N + i][snk] = cost[i];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (requires[i][j] == 1) {
        capacity[2 + i][2 + N + j] = MAX_I;
      }
    }
  }
  int P = std::accumulate(profit.begin(), profit.end(), 0);
  int C = ford_fulkerson(src, snk);
  return P - C;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    profit.resize(N);
    cost.resize(M);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &profit[i]);
    }
    for (int i = 0; i < M; ++i) {
      scanf("%d", &cost[i]);
    }
    // init variables
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        flow[i][j] = 0;
        capacity[i][j] = 0;
        int a;
        scanf("%d", &a);
        requires[i][j] = a;
      }
    }
    printf("%d\n", solve());
  }

  return 0;
}
