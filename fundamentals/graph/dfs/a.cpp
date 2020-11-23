// Copyright (C) 2017 by iamslash

#include <vector>
#include <cstdio>

const int V = 7;
std::vector<std::vector<int> > adj;

void dfs(std::vector<bool>& visited, int here) {
  printf("%d ", here);
  visited[here] = true;
  for (int i = 0; i < adj[here].size(); ++i) {
    int child = adj[here][i];
    if (visited[child] == false) {
      dfs(visited, child);
    }
  }
}

void dfs_all() {
  std::vector<bool> visited(V, false);
  for (int i = 0; i < V; ++i) {
    if (visited[i] == false) {
      dfs(visited, i);
    }
  }
}

int main() {

  adj.resize(V);
  for (int i = 0; i < adj.size(); ++i)
    adj[i].clear();

  adj[0].push_back(1);
  adj[0].push_back(2);

  adj[1].push_back(0);
  adj[1].push_back(3);
  adj[1].push_back(4);
  adj[1].push_back(5);

  adj[2].push_back(0);
  adj[2].push_back(3);

  adj[3].push_back(1);
  adj[3].push_back(2);
  adj[3].push_back(4);
  adj[3].push_back(5);

  adj[4].push_back(3);

  adj[5].push_back(1);
  adj[5].push_back(3);
  adj[5].push_back(6);

  adj[6].push_back(1);
  adj[6].push_back(5);

  // printf("before DfsAll\n");
  
  dfs_all();

  printf("\n");
  
  return 0;
}
