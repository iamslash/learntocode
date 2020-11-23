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

int Dijkstra(const std::vector<int>& fireplace,
             const std::vector<int>& firehouse) {
  std::vector<int> dist(V, std::numeric_limits<int>::max());
  std::priority_queue<std::pair<int, int> > pq;

  // push firehouse
  for (const int& i : firehouse) {
    pq.push(std::make_pair(0, i));
  }

  while (!pq.empty()) {
    int herenode = pq.top().second;
    int herecost = -pq.top().first;
    pq.pop();

    if (dist[herenode] < herecost)
      continue;

    // visit neighbors
    for (int i = 0; i < adj[herenode].size(); ++i) {
      int therenode = adj[herenode][i].first;
      int therecost = herecost + adj[herenode][i].second;
      if (dist[therenode] > therecost) {
        dist[therenode]= therecost;
        pq.push(std::make_pair(-therecost, therenode));
      }
    }
  }

  // sum dist of fireplace
  int r = 0;
  for (const int& i : fireplace) {
    r += dist[i];
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
    printf("%d\n", Dijkstra(fireplace, firehouse));
  }

  return 0;
}


