// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/TPATH

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_V 2000
#define MAX_I 987654321

int N, M;

std::vector<std::pair<int, int> > adj[MAX_V];

void Dfs(int lo, int hi, int here, std::vector<bool>& visited) {
  visited[here] = true;
  // base condition
  if (here == N - 1)
    return;
  // recursion
  for (int i = 0; i < adj[here].size(); ++i) {
    int next = adj[here][i].first;
    int cost = adj[here][i].second;
    if (cost < lo || cost > hi)
        continue;
    if (!visited[next]) {
      Dfs(lo, hi, next, visited);
    }
  }
}

// is there path which have v between lo and hi ???
bool HasPath(int lo, int hi) {
  std::vector<bool>visited(N, false);
  Dfs(lo, hi, 0, visited);
  return visited[N - 1];
}

int Solve(const std::vector<int>& weights) {
  int lo = 0;
  int hi = 0;
  // int hi = N - 1;
  int r = MAX_I;

  while (true) {
    // printf("%d %d\n", lo, hi);
    if (HasPath(weights[lo], weights[hi])) {
      r = std::min(r, weights[hi] - weights[lo]);
      lo++;
    } else {
      if (hi == N - 1) // if (hi <= lo)
        break;
      hi++;
    }
  }

  return r;
}


int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < MAX_V; ++i) {
      adj[i].clear();
    }
    scanf("%d %d", &N, &M);
    std::vector<int> weights;
    for (int i = 0; i < M; ++i) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      weights.push_back(c);
      adj[a].push_back(std::make_pair(b, c));
      adj[b].push_back(std::make_pair(a, c));
    }
    std::sort(weights.begin(), weights.end());
    printf("%d\n", Solve(weights));
  }

  return 0;
}
