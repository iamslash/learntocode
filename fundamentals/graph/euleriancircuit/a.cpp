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

std::vector<int> euler_circuit(std::vector<std::vector<int>>& adj) {
  std::vector<int> order;
  dfs(adj, order, 0);
  std::reverse(order.begin(), order.end());
  return order;
}

int main() {

  std::vector<std::vector<int>> adj = std::vector<std::vector<int>>(5, std::vector<int>(5, 0));
    adj[0][1] = 1;
    adj[1][0] = 1;
    adj[0][2] = 1;
    adj[2][0] = 1;
    adj[0][4] = 1;
    adj[4][0] = 1;
    adj[1][2] = 1;
    adj[2][1] = 1;
    adj[2][3] = 1;
    adj[3][2] = 1;
    adj[3][4] = 1;
    adj[4][3] = 1;

  auto r = euler_circuit(adj);
  
  for (int a : r)
    printf("%d ", a);
  printf("\n");
 
  return 0;
}
