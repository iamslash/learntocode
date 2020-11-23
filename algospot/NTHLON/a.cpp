// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/NTHLON
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>

#define MAX_INT 987654321
int M;
#define VMAX 410
const int START = 401;

std::vector<std::pair<int, int> > adj[VMAX];

// node number should be greater than zero
int vertex(int delta) {
  return delta + 200;
}

std::vector<int> dijkstra(int src) {
  std::vector<int> dist(VMAX, MAX_INT);
  std::priority_queue<std::pair<int, int> > pq;
  dist[src] = 0;
  pq.push(std::make_pair(0, src));
  while (!pq.empty()) {
    int herenode = pq.top().second;
    int herecost = -pq.top().first;
    pq.pop();
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
  return dist;
}

int solve(const std::vector<int>& a,
          const std::vector<int>& b) {
  for (int i = 0; i < a.size(); ++i) {
    int delta = a[i] - b[i];
    adj[START].push_back(std::make_pair(vertex(delta), a[i]));
  }
  for (int delta = -199; delta <= 199; ++delta) {
    for (int i = 0; i < a.size(); ++i) {
      int next = delta + a[i] - b[i];
      if (abs(next) > 200)
        continue;
      adj[vertex(delta)].push_back(std::make_pair(vertex(next), a[i]));
    }
  }
  std::vector<int> shortest = dijkstra(START);
  int r = shortest[vertex(0)];
  if (r == MAX_INT)
    return -1;
  return r;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < VMAX; ++i)
      adj[i].clear();
    scanf("%d", &M);
    std::vector<int> a(M, -1);
    std::vector<int> b(M, -1);

    for (int i = 0; i < M; ++i) {
      scanf("%d %d", &a[i], &b[i]);
    }

    int r = solve(a, b);
    if (r >= 0) {
      printf("%d", r);
    } else {
      printf("IMPOSSIBLE");
    }
    printf("\n");
  }

  return 0;
}


