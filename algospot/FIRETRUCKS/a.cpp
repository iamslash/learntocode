// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/FIRETRUCKS
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits>

int V, E, N, M;

std::vector<std::pair<int, int> > adj[1000];

int dijkstra(const std::vector<int>& fireplace,
             const std::vector<int>& firehouse) {
  std::vector<int> dist;
  std::priority_queue<std::pair<int, int> > pq;
  for (int i = 0; i < fireplace.size(); ++i) {
    int f = fireplace[i] - 1;
    dist[f] = 0;
    pq.push(std::make_pair(0, f));
  }

  while (!pq.empty()) {
    int herenode = pq.top().second;
    int herecost = -pq.top().first;

    if (dist[herenode] < herecost)
      continue;

    for (int i = 0; i < adj[herenode].size(); ++i) {
      int therenode = adj[herenode][i].first;
      int therecost = herecost + adj[herenode][i].second;
      if (dist[therenode] > therecost) {
        dist[therenode] = therecost;
        pq.push(std::make_pair(-therecost, therenode));
      }
    }
  }

  int r = 0;
  for (int i = 0; i < firehouse.size(); ++i) {
    int f = firehouse[i] - 1;
    r += dist[f];
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 1000; ++i)
      adj[i].clear();
    scanf("%d %d %d %d", &V, &E, &N, &M);
    std::vector<int> fireplace(N, -1);
    std::vector<int> firehouse(M, -1);

    for (int i = 0; i < E; ++i) {
      int src;
      int dst;
      int cost;
      scanf("%d %d %d", &src, &dst, &cost);
      src--;
      dst--;
      adj[src].push_back(std::make_pair(dst, cost));
      adj[dst].push_back(std::make_pair(src, cost));
    }

    for (int i = 0; i < N; ++i) {
      scanf("%d", &fireplace[i]);
      fireplace[i]--;
    }
    for (int i = 0; i < M; ++i) {
      scanf("%d", &firehouse[i]);
      firehouse[i]--;
    }
    printf("%d\n", dijkstra(fireplace, firehouse));
  }

  return 0;
}


