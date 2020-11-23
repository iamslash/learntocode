// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>

#define MAX_INT 987654321

int V = 7;
std::vector<std::pair<int, int> > adj[V];

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("[%c]%d ", 'a'+i, v[i]);
  }
  printf("\n");
}

std::vector<int> dijkstra(int src) {
  std::vector<int> dist(V, MAX_INT);
  std::vector<bool> visited(V, false);
  dist[src] = 0;
  visited[src] = false;
  while (true) {
    // find a u vertex which is not visited yet.
    int closest = MAX_INT;
    int u;
    for (int i = 0; i < V; ++i) {
      if (dist[i] < closest && !visited[i]) {
        u = i;
        closest = dist[i];
      }
    }
    if (closest == MAX_INT)
      break;
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i].first;
      if (visited[v])
        continue;
      int d2v = dist[u] + adj[u][i].second;
      dist[v] = std::min(dist[v], d2v);
    }
  }
  return dist;
}

int main() {
  for (int i = 0; i < V; ++i)
    adj[i].clear();

  adj[0].push_back(std::make_pair(1, 5));
  adj[0].push_back(std::make_pair(2, 1));

  adj[1].push_back(std::make_pair(0, 5));
  adj[1].push_back(std::make_pair(3, 1));
  adj[1].push_back(std::make_pair(5, 3));
  adj[1].push_back(std::make_pair(6, 3));

  adj[2].push_back(std::make_pair(0, 1));
  adj[2].push_back(std::make_pair(3, 2));

  adj[3].push_back(std::make_pair(1, 1));
  adj[3].push_back(std::make_pair(2, 2));
  adj[3].push_back(std::make_pair(4, 5));
  adj[3].push_back(std::make_pair(6, 3));

  adj[4].push_back(std::make_pair(3, 5));

  adj[5].push_back(std::make_pair(1, 3));
  adj[5].push_back(std::make_pair(6, 2));

  adj[6].push_back(std::make_pair(1, 3));
  adj[6].push_back(std::make_pair(3, 3));
  adj[6].push_back(std::make_pair(5, 2));

  std::vector<int> r = dijkstra(0);

  print_v_int(r);

  return 0;
}
