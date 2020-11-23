// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <algorithm>

int N = 5;
std::vector<std::vector<int> > adj;
std::vector<bool> visited;
std::vector<int> order;

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void dfs(int here) {
  visited[here] = true;
  for (int next = 0; next < N; ++next) {
    if (adj[here][next] > 0 && visited[next] == false)
      dfs(next);
  }
  order.push_back(here);
}

void dfs_all() {
  for (int i = 0; i < N; ++i) {
    if (visited[i] == false)
      dfs(i);
  }
}

std::vector<int> topological_sort() {
  dfs_all();
  std::reverse(order.begin(), order.end());

  // check invalid edge direction
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (adj[order[j]][order[i]] > 0)
        return std::vector<int>();
    }
  }

  return order;
}

int main() {
  adj = std::vector<std::vector<int> >(N, std::vector<int>(N, 0));
  // visited 를 모두 false로 초기화한다.
  visited = std::vector<bool>(N, false);

  adj[0][1] = 1;
  adj[0][2] = 1;
  adj[3][2] = 1;
  adj[4][3] = 1;

  std::vector<int> c = topological_sort();
  print_v_int(c);

  // adj[0][4] = 1;
  // dfs_all();
  // print_v_int(order);
  return 0;
}
