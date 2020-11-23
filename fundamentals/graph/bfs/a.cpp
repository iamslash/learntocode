// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <queue>

using ADJ = std::vector<std::vector<int>>;

ADJ adj;
int N = 10;

void print_v_int(std::vector<int> v) {
  for (auto e : v) {
    printf("%d ", e);
  }
  printf("\n");
}

std::vector<int> bfs(int root) {
  std::vector<int> order;
  std::vector<bool> found(N, false);
  std::queue<int> q;
  order.push_back(root);
  found[root] = true;
  q.push(root);

  while (!q.empty()) {
    int here = q.front(); q.pop();
    for (int i = 0; i < adj[here].size(); ++i) {
      int next = adj[here][i];
      if (!found[next]) {
        found[next] = true;
        order.push_back(next);
        q.push(next);
      }
    }
  }
  
  return order;
}

int main() {
  adj.clear();
  adj.resize(N);
  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(3);

  std::vector<int> r = bfs(0);

  print_v_int(r);

  return 0;
}
