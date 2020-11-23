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
// MST partial dynamic programming
////////////////////////////////////////////////////////////////////////////////

const int CACHED_DEPTH = 5;
// CACHE[here][remained vertex][visited]
std::map<int, double> CACHE[MAX][CACHED_DEPTH + 1];

double dp(int here, int visited) {
  // base condition
  if (visited == (1 << N) - 1)
    return DIST[here][0];
  // memoization
  int remaining = N - __builtin_popcount(visited);
  double& r = CACHE[here][remaining][visited];
  if (r > 0)
    return r;
  // recursion
  r = INF;
  for (int next = 0; next < N; ++next) {
    if (visited & (1 << next))
      continue;
    r = std::min(r, dp(next, visited + (1 << next))
                 + DIST[here][next]);
  }
  return r;
}

void _solve_partial_dp(std::vector<int>& path,
                                 int& visited, int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (path.size() + CACHED_DEPTH >= N) {
    BEST = std::min(BEST, past_dist + dp(path.back(), visited));
    return;
  }
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited & (1 << next))
      continue;
    visited + (1 << next);
    path.push_back(next);
    _solve_partial_dp(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited - (1 << next);
  }   
}

double solve_partial_dp() {
  // init CACHE
  for (int i = 0; i < MAX; ++i)
    for (int j = 0; j <= CACHED_DEPTH; ++j)
      CACHE[i][j].clear();
  BEST = INF;
  int visited = 1;
  std::vector<int> path(1, 0);
  _solve_partial_dp(path, visited, 0);
  return BEST;
}

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

////////////////////////////////////////////////////////////////////////////////
// swapping past paths pruning
////////////////////////////////////////////////////////////////////////////////

// check last 4 elements of path
// if swapping them past_dist can be shorter???
bool path_swap_prunig(const std::vector<int>& path) {
  if (path.size() < 4)
    return false;
  int p = path[path.size() - 4];
  int a = path[path.size() - 3];
  int b = path[path.size() - 2];
  int q = path[path.size() - 1];
  return DIST[p][a] + DIST[b][q] >
      DIST[p][b] + DIST[a][q];
}

// check sub elements of path except start, end element
// if swapping them past_dist can be shorter???
bool path_reverse_pruning(const std::vector<int>& path) {
  if (path.size() < 4)
    return false;
  int b = path[path.size() - 2];
  int q = path[path.size() - 1];
  for (int i = 0; i + 3 < path.size(); ++i) {
    int p = path[i];
    int a = path[i+1];
    if (DIST[p][a] + DIST[b][q] >
      DIST[p][b] + DIST[a][q])
      return true;
  }
  return false;
}

void _solve_swapping_past_paths_pruning(std::vector<int>& path,
                                std::vector<bool>& visited,
                                        int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (path_swap_prunig(path))
    return;
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_swapping_past_paths_pruning(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }  
}

double solve_swapping_past_paths_pruning() {
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_swapping_past_paths_pruning(path, visited, 0);
  return BEST;
}


////////////////////////////////////////////////////////////////////////////////
// greedy
////////////////////////////////////////////////////////////////////////////////
std::vector<int> NEAREST[MAX];

void _solve_greedy(std::vector<int>& path,
                                std::vector<bool>& visited,
                                int past_dist) {
  // init NEAREST
  for (int i = 0; i < N; ++i) {
  }
  
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (BEST <= past_dist)
    return;
  // recursion
  for (int i = 0; i < NEAREST[here].size(); ++i) {
    int next = NEAREST[here][i];
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_greedy(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }
}

double solve_greedy() {
  // init NEAREST
  for (int i = 0; i < N; ++i) {
    std::vector<std::pair<double, int> > order;
    for (int j = 0; j < N; ++j) {
      if (i != j)
        order.push_back(std::make_pair(DIST[i][j], j));
    }
    std::sort(order.begin(), order.end());
    NEAREST[i].clear();
    for (int j = 0; j < order.size(); ++j)
      NEAREST[i].push_back(order[j].second);
  }
  
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_greedy(path, visited, 0);
  return BEST;
}

////////////////////////////////////////////////////////////////////////////////
// simple heuristic pruning
////////////////////////////////////////////////////////////////////////////////
double MIN_EDGE[MAX];

double simple_heuristic(std::vector<bool>& visited) {
  double r = MIN_EDGE[0];
  for (int i = 0; i < N; ++i) {
    if (!visited[i])
      r += MIN_EDGE[i];    
  }
  return r;
}

void _solve_simple_heuristic_pruning(std::vector<int>& path,
                                std::vector<bool>& visited,
                                int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (BEST <= past_dist + simple_heuristic(visited))
    return;
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_simple_heuristic_pruning(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }
}

double solve_simple_heuristic_pruning() {
  // init heuristic
  for (int i = 0; i < N; ++i) {
    MIN_EDGE[i] = INF;
    for (int j = 0; j < N; ++j) {
      if (i != j)
        MIN_EDGE[i] = std::min(MIN_EDGE[i], DIST[i][j]);
    }
  }
  
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_simple_heuristic_pruning(path, visited, 0);
  return BEST;
}

////////////////////////////////////////////////////////////////////////////////
// simple pruning
////////////////////////////////////////////////////////////////////////////////
void _solve_simple_pruning(std::vector<int>& path,
                                std::vector<bool>& visited,
                                int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // pruning
  if (BEST <= past_dist)
    return;
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_simple_pruning(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }
}

double solve_simple_pruning() {
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_simple_pruning(path, visited, 0);
  return BEST;
}

////////////////////////////////////////////////////////////////////////////////
// backtracking
////////////////////////////////////////////////////////////////////////////////
void _solve_backtracking(std::vector<int>& path,
                                std::vector<bool>& visited,
                                int past_dist) {
  int here = path.back();
  // base condition
  if (path.size() == N) {
    BEST = std::min(BEST, past_dist + DIST[here][0]);
  }
  // recursion
  for (int next = 0; next < N; ++next) {
    if (visited[next])
      continue;
    visited[next] = true;
    path.push_back(next);
    _solve_backtracking(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited[next] = false;
  }
}

double solve_backtracking() {
  BEST = INF;
  std::vector<bool> visited(N, false);
  std::vector<int> path(1, 0);
  visited[0] = true;
  _solve_backtracking(path, visited, 0);
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
    printf("%lf\n", solve_backtracking());
  }
  return 0;
}
