/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<int>>& adj,
         std::vector<int>& order, int u) {
  for (int v = 0; v < 5; ++v) {
    while (adj[u][v]) {
      adj[u][v]--;
      adj[v][u]--;
      dfs(adj, order, v);
    }
  }
  order.push_back(u);
}

std::vector<int> euler_trail(
    std::vector<std::vector<int>>& adj, int u, int v) {
  std::vector<int> order;
  adj[u][v] = 1;
  adj[v][u] = 1;
  dfs(adj, order, 0);
  std::reverse(order.begin(), order.end());
  order.pop_back();
  return order;
}

int main() {

  std::vector<std::vector<int>> adj = std::vector<std::vector<int>>(5, std::vector<int>(5, 0));
  adj[0][1] = 1;
  adj[1][0] = 1;
  adj[1][2] = 1;
  adj[2][1] = 1;

  auto r = euler_trail(adj, 0, 2);
  
  for (int a : r)
    printf("%d ", a);
  printf("\n");
 
  return 0;
}
