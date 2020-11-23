// Copyright (C) 2016 by iamslash

// get shortest path by bfs

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <queue>

int N = 5;

std::vector<std::vector<int> > adj;

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}


std::vector<int> bfs(int start) {
  std::vector<int> distance(N, -1);
  std::vector<int> parent(N, -1);
  std::queue<int> q;
  distance[start] = 0;
  parent[start] = start;
  q.push(start);
  while (!q.empty()) {
    int here = q.front();
    q.pop();
    for (int i = 0; i < adj[here].size(); ++i) {
      int there = adj[here][i];
      if (distance[there] == -1) {
        q.push(there);
        distance[there] = distance[here] + 1;
        parent[there] = here;
      }
    }
  }
  return parent;
}

std::vector<int> get_shortest_path(int start, int end) {
  std::vector<int> parent = bfs(start);
  std::vector<int> r(1, end);
  int v = end;
  while (parent[v] != v) {
    // printf("%d\n", parent[v]);
    v = parent[v];
    r.push_back(v);
  }
  std::reverse(r.begin(), r.end());

  return r;
}

int main() {
  adj.clear();
  adj.resize(N);
  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(3);

  // 0부터 3까지 최단 경로 구하기
  std::vector<int> r = get_shortest_path(0, 3);
  print_v_int(r);

  return 0;
}
