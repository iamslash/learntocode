// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <map>

const int MAXI = 987654321;
const int MAXV = 100;
int V = 5;

int prim(int (&graph)[5][5],
         std::vector<std::pair<int, int>>& mst) {
  int r = 0;
  
  std::vector<bool> added(V, false);  // is added to mst
  std::vector<int> mincost(V, MAXI);
  std::vector<int> parent(V, -1);

  mincost[0]   = 0;
  parent[0]    = 0;

  for (int i = 0; i < V; ++i) {
    int u = -1;
    // find u with minimum weight among nodes not visited
    for (int v = 0; v < V; ++v) {
      if (added[v] == false && (u == -1 || mincost[v] < mincost[u]))
        u = v;
    }
    
    // start node does not need to add to mst
    if (parent[u] != u) {
      mst.emplace_back(parent[u], u);
    }
    added[u] = true;
    r += mincost[u];
    // find neighbor nodes
    for (int v = 0; v < V; ++v) {
      int duv = graph[u][v];
      if (added[v] == false && duv > 0 && duv < mincost[v]) {
        parent[v] = u;
        mincost[v] = duv;
      }
    }
  }
  
  return r;
}

int main() {
  int graph[5][5] = {{0, 2, 0, 6, 0},
                           {2, 0, 3, 8, 5},
                           {0, 3, 0, 0, 7},
                           {6, 8, 0, 0, 9},
                           {0, 5, 7, 9, 0},};
  std::vector<std::pair<int, int>> mst;
  printf("%d\n", prim(graph, mst));
  for (const auto& e : mst) {
    printf("%d - %d\n", e.first, e.second);
  }
  return 0;
}

