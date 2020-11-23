// Copyright (C) 2016 by iamslash
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

const int MAX_V = 100;
const int MAX_I = 987654321;
int V;
std::vector<std::pair<int, int> > adj[MAX_V];

int prim(std::vector<std::pair<int, int> >& mst) {
  int r = 0;
  mst.clear();
  std::vector<bool> added(V, false);
  std::vector<int> min_weight(V, MAX_I); // min_weight[i] : min dist to i vertex
  std::vector<int> parent(V, -1);
  min_weight[0] = 0;
  parent[0] = 0;
  for (int k = 0; k < V; ++k) {
    int here = -1;
    // find here which has min dist from somewhere to here
    for (int v = 0; v < V; ++v) {
      if (!added[v] && (here == -1 || min_weight[here] > min_weight[v]))
        here = v;
    }
    // I found here
    if (parent[here] != here)
      mst.push_back(std::make_pair(parent[here], here));
    r += min_weight[here];
    added[here] = true;
    // explorer neighbors
    for (int i = 0; i < adj[here].size(); ++i) {
      int next = adj[here][i].first;
      int dist = adj[here][i].second;
      if (!added[next] && min_weight[next] > dist) {
        parent[next] = here;
        min_weight[next] = dist;
      }
    }   
  }
  return r;
}

int main() {
  V = 5;
  for (int i = 0; i < MAX_V; ++i)
    adj[i].clear();
  
  adj[0].push_back(std::make_pair(1, 2));
  adj[0].push_back(std::make_pair(3, 6));

  adj[1].push_back(std::make_pair(0, 2));
  adj[1].push_back(std::make_pair(2, 3));
  adj[1].push_back(std::make_pair(3, 8));
  adj[1].push_back(std::make_pair(4, 5));

  adj[2].push_back(std::make_pair(1, 3));
  adj[2].push_back(std::make_pair(4, 7));

  adj[3].push_back(std::make_pair(0, 6));
  adj[3].push_back(std::make_pair(1, 8));
  adj[3].push_back(std::make_pair(4, 9));

  adj[4].push_back(std::make_pair(1, 5));
  adj[4].push_back(std::make_pair(2, 7));
  adj[4].push_back(std::make_pair(3, 9));

  std::vector<std::pair<int, int> > mst;
  printf("%d\n", prim(mst));

  for (const std::pair<int, int>& p : mst) {
    printf("%d -> %d\n", p.first, p.second);
  }

  return 0;
}
