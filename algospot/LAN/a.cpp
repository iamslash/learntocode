// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/LAN

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_V 500
#define MAX_I 987654321

int N, M;
double adj[MAX_V][MAX_V];

struct OptimizedDisjointSet {
  std::vector<int> parent, rank;
  explicit OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }
  int find(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (rank[u] > rank[v])
      std::swap(u, v);
    // always rank[v] > rank[u] u should be child of v
    parent[u] = v;
    if (rank[u] == rank[v])
      ++rank[v];
  }
};

double Kruskal(std::vector<std::pair<int, int> > * selected) {
  double r = 0;
  selected->clear();
  std::vector<std::pair<double, std::pair<int, int> > > edges;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      edges.push_back(std::make_pair(adj[i][j], std::make_pair(i, j)));
    }
  }
  std::sort(edges.begin(), edges.end());
  OptimizedDisjointSet sets(N);
  for (int i = 0; i < edges.size(); ++i) {
    double dist = edges[i].first;
    int u = edges[i].second.first;
    int v = edges[i].second.second;
    // connected already???
    if (sets.find(u) == sets.find(v))
      continue;
    sets.merge(u, v);
    selected->push_back(std::make_pair(u, v));
    r += dist;
  }

  return r;
}

double GetDist(const std::vector<int>& v_x,
               const std::vector<int>& v_y,
               int from, int to) {
  int x0 = v_x[from];
  int x1 = v_x[to];
  int y0 = v_y[from];
  int y1 = v_y[to];
  int diff_x = x1 - x0;
  int diff_y = y1 - y0;
  return sqrt(diff_x * diff_x + diff_y * diff_y);
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    std::vector<int> v_x(N);
    std::vector<int> v_y(N);

    for (int i = 0; i < N; ++i) {
      scanf("%d", &v_x[i]);
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d", &v_y[i]);
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        adj[i][j] = GetDist(v_x, v_y, i, j);
      }
    }
    for (int i = 0; i < M; ++i) {
      int a, b;
      scanf("%d %d", &a, &b);
      adj[a][b] = 0;
    }
    std::vector<std::pair<int, int> > r;
    printf("%0.10lf\n", Kruskal(&r));
  }

  return 0;
}
