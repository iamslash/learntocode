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
    printf("%lf\n", solve_greedy());
  }
  return 0;
}
