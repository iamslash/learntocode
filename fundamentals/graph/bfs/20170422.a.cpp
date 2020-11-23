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

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

// start에서 시작해 그래프를 너비 우선 탐새갛고 각 정점의 방문 순서를 반환한다.
std::vector<int> Bfs(int start) {
  // 각 정점의 방문 여부
  std::vector<bool> discovered(adj.size(), false);
  // 방문할 정점 목록을 유지하는 큐
  std::queue<int> q;
  // 정점의 방문 순서
  std::vector<int> order;
  discovered[start] = true;
  q.push(start);
  while (!q.empty()) {
    int here = q.front();
    q.pop();
    // here를 방문한다.
    order.push_back(here);

    // 모든 인접한 정점을 검사한다.
    for (int i = 0; i < adj[here].size(); ++i) {
      int there = adj[here][i];
      // 처음 보는 정점이면 방문 목록에 집어 넣는다.
      if (!discovered[there]) {
        q.push(there);
        discovered[there] = true;
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

  std::vector<int> r = Bfs(0);

  PrintVInt(r);

  return 0;
}
