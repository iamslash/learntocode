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
    printf("%lf\n", solve_swapping_past_paths_pruning());
  }
  return 0;
}
