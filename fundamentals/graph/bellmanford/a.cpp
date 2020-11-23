// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>
#include <limits>

#define MAX_V 6
const int MAX_INT = 987654321;

int V = MAX_V;

std::vector<std::pair<int, int> > adj[MAX_V];

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

// return empty vector if v is a negative cycle.
std::vector<int> bellmanford(int src) {
  std::vector<int> dist(V, MAX_INT);
  dist[src] = 0;
  bool updated = false;
  for (int i = 0; i < V; ++i) {
    updated = false;
    for (int u = 0; u < V; ++u) {
      for (int j = 0; j < adj[u].size(); ++j) {
        int v = adj[u][j].first;
        int duv = adj[u][j].second;  // distance of u-v
        if (dist[v] > dist[u] + duv) {
          dist[v] = dist[u] + duv;
          updated = true;
        }
      }
    }
    // if v is no relax, terminate loop
    if (!updated)
      break;
  }
  // v is a negative cycle if v is relax at last loop.
  if (updated)
    dist.clear();
  return dist;
}

int main() {
  for (int i = 0; i < MAX_V; ++i)
    adj[i].clear();

  adj[0].push_back(std::make_pair(1, 10));
  adj[0].push_back(std::make_pair(5, 8));
  adj[1].push_back(std::make_pair(3, 2));
  adj[2].push_back(std::make_pair(1, 1));
  adj[3].push_back(std::make_pair(2, -2));
  adj[4].push_back(std::make_pair(1, 2));
  adj[4].push_back(std::make_pair(3, -1));
  adj[5].push_back(std::make_pair(4, 1));

  std::vector<int> r = bellmanford(0);

  print_v_int(r);


  return 0;
}
