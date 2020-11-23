// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/ROUTING
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits>

#define MAX_INT 987654321

int N, M;

std::vector<std::pair<int, double> > adj[10000];

double dijkstra(int src) {
  double r;
  std::vector<double> dist(N, std::numeric_limits<double>::max());
  dist[src] = 0;
  std::priority_queue<std::pair<double, int> > pq;
  pq.push(std::make_pair(0, src));
  while (!pq.empty()) {
    int herecost = -pq.top().first;
    int herenode = pq.top().second;
    pq.pop();
    if (dist[herenode] < herecost)
      continue;
    for (int i = 0; i < adj[herenode].size(); ++i) {
      int therenode = adj[herenode][i].first;
      int therecost = herecost * adj[herenode][i].second;
      if (therecost < dist[therenode]) {
        dist[therenode] = therecost;
        pq.push(std::make_pair(-therecost, therenode));
      }
    }
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < 10000; ++i)
      adj[i].clear();
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
      int src;
      int dst;
      double sig;
      scanf("%d %d %lf", &src, &dst, &sig);
      adj[src].push_back(std::make_pair(dst, sig));
      adj[dst].push_back(std::make_pair(src, sig));
    }
    printf("%f\n", dijkstra(0));
  }

  return 0;
}


