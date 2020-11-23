// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/TSP2

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

const double INF = 1e200;
const int MAX = 15;
int N;
double DIST[MAX][MAX];
double BEST;

////////////////////////////////////////////////////////////////////////////////
// solve mst heuristic pruning
////////////////////////////////////////////////////////////////////////////////

struct DisjointSet {
  std::vector<int> parent, rank;
  explicit DisjointSet(int n) : parent(n), rank(n, 1) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }
  int find(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = find(parent[u]);
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (rank[u] > rank[v])
      std::swap(u, v);
    // always rank[v] > rank[u] u should be child of v
    parent[u] = v;
    if (rank[u] == rank[v])
      ++rank[v];
    return true;
  }
};

std::vector<std::pair<double, std::pair<int, int> > > EDGES;

double mst_heuristic(int here, const std::vector<bool>& visited) {
  // Kruskal's MST
  DisjointSet sets(N);
  double taken = 0;
  for (int i = 0; i < EDGES.size(); ++i) {
    int a = EDGES[i].second.first;
    int b = EDGES[i].second.second;
    if (a != 0 && a != here && visited[a])
      continue;
    if (b != 0 && b != here && visited[b])
      continue;
    if (sets.merge(a, b))
      taken += EDGES[i].first;
  }
  return taken;
}

void _solve_mst_heuristic_pruning(std::vector<int>& path,
                                std::vector<bool>& visited,
                                        int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (BEST <= past_dist + mst_heuristic(here, visited))
    return;
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_mst_heuristic_pruning(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }   
}

double solve_mst_heuristic_pruning() {
  // init EDGES
  EDGES.clear();
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < i; ++j)
      EDGES.push_back(std::make_pair(DIST[i][j], std::make_pair(i, j)));
  std::sort(EDGES.begin(), EDGES.end());
  
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_mst_heuristic_pruning(path, visited, 0);
  return BEST;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%lf", &DIST[i][j]);
      }
    }
    printf("%lf\n", solve_mst_heuristic_pruning());
  }
  return 0;
}
