// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <queue>

int N = 5;

// 그래프의 인접 행렬
// adj[i][j] = i와 j사이의 간선의 수
std::vector<std::vector<int> > adj;

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

std::vector<int> bfs(int root) {
  std::vector<bool> discovered(N, false);
  std::vector<int> r;
  std::queue<int> q;
  q.push(root);

  while (!q.empty()) {
    int here = q.front();
    q.pop();
    r.push_back(here);
    for (int i = 0; i < adj[here].size(); ++i) {
      int there = adj[here][i];
      if (discovered[there] == false) {
        q.push(there);
        discovered[there] = true;
      }
    }
  }

  return r;
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
