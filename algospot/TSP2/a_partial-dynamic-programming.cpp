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
// partial dynamic programming
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
    visited += (1 << next);
    path.push_back(next);
    _solve_partial_dp(path, visited, past_dist + DIST[here][next]);
    path.pop_back();
    visited -= (1 << next);
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
    printf("%lf\n", solve_partial_dp());
  }
  return 0;
}
