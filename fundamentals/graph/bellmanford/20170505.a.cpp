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

std::vector<int> BellmanFord(int src) {
  std::vector<int> upper(V, MAX_INT);
  upper[src] = 0;
  bool updated;
  for (int iter = 0; iter < V; ++iter) {
    updated = false;
    for (int herenode = 0; herenode < V; ++herenode) {
      // printf("%d\n", herenode);
      for (int i = 0; i < adj[herenode].size(); ++i) {
        int therenode = adj[herenode][i].first;
        int therecost = adj[herenode][i].second;

        if (upper[therenode] > upper[herenode] + therecost) {
          upper[therenode] = upper[herenode] + therecost;
          updated = true;
          printf(" %d -> %d %d\n", herenode, therenode, upper[therenode]);
        }
      }
    }
    if (!updated)
      break;
  }

  if (!updated)
    upper.clear();

  return upper;
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
  
  std::vector<int> r = BellmanFord(0);

  // PrintVInt(r);
  
  
  return 0;
}
