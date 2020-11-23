// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/TIMETRIP

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_V 100
#define MAX_INT 987654321

int V, W;
std::vector<std::pair<int, int> > adj[MAX_V];
bool reachable[MAX_V][MAX_V];

int bellmanfordmin(int src, int dst) {
  std::vector<int> upper(V, MAX_INT);
  upper[src] = 0;
  bool updated = false;
  for (int i = 0; i < V; ++i) {
    updated = false;
    for (int herenode = 0; herenode < V; ++herenode) {
      int herecost  = upper[herenode];
      int therenode = adj[herenode][i].first;
      int therecost = herecost + adj[herenode][i].second;
      if (upper[therenode] > therecost) {
        upper[therenode] = therecost;
        updated = true;
      }
    }
    if (!updated)
      break;
  }
  if (updated)
    upper.clear();
  return upper[dst];
}

int bellmanfordmax(int src, int dst) {
  std::vector<int> upper(V, MAX_INT);
  upper[src] = 0;
  bool updated = false;
  for (int i = 0; i < V; ++i) {
    updated = false;
    for (int herenode = 0; herenode < V; ++herenode) {
      int herecost  = upper[herenode];
      int therenode = adj[herenode][i].first;
      int therecost = herecost + adj[herenode][i].second;
      if (upper[therenode] < therecost) {
        upper[therenode] = therecost;
        updated = true;
      }
    }
    if (!updated)
      break;
  }
  if (updated)
    upper.clear();
  return upper[dst];
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < MAX_V; ++i) {
      adj[i].clear();
      for (int j = 0; j < MAX_V; ++j) {
        reachable[i][j] = (i == j ? true : false);
      }
    }
    scanf("%d %d", &V, &W);
    for (int i = 0; i < W; ++i) {
      int a, b, d;
      scanf("%d %d %d", &a, &b, &d);
      adj[a].push_back(std::make_pair(b, d));
      reachable[a][b] = true;
      // reachable[b][a] = true;
    }
    // set reachable
    for (int k = 0; k < MAX_V; ++k) {
      for (int i = 0; i < MAX_V; ++i) {
        for (int j = 0; j < MAX_V; ++j) {
          reachable[i][j] |= reachable[i][k] && reachable[k][j];
        }
      }
    }

    // print result
    if (reachable[0][1] == false) {
      printf("UNREACHABLE");
    } else {
      int nmin = bellmanfordmin(0, 1);
      int nmax = bellmanfordmax(0, 1);
      if (nmin <= -MAX_INT) {
        printf("INFINITY ");
      } else {
        printf("%d ", nmin);
      }
      if (nmax >= MAX_INT) {
        printf("INFINITY");
      } else {
        printf("%d", nmax);
      }
    }
    printf("\n");
  }

  return 0;
}
