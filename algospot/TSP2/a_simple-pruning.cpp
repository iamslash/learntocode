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
    printf("%lf\n", solve_simple_pruning());
  }
  return 0;
}
