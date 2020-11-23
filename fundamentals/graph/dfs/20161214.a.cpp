// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>

int N = 5;

// 그래프의 인접 행렬
// adj[i][j] = i와 j사이의 간선의 수
std::vector<std::vector<int> > adj;
std::vector<bool> visited;

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
}

void Dfs(int here) {
  // std::cout << "DFS visits " << here << endl;
  printf("DFS visits %d\n", here);
  visited[here] = true;
  // 모든 인접 정점을 순회하면서
  for (int i = 0; i < adj[here].size(); ++i) {
    int there = i;
    // 아직 방문한 적 없다면 방문한다.
    if (adj[here][there] > 0 && !visited[there])
      Dfs(there);
  }
  // 더 이상 방문 할 정점이 없으니, 재귀 호출을 종료하고 이전 정점으로
  // 돌아간다.
}

// 서로 연결되지 않은 graph까지 탐색한다.
void DfsAll() {
  // visited 를 모두 false로 초기화한다.
  visited = std::vector<bool>(adj.size(), false);
  // 모든 정점을 순회하면서, 아직 방문한 적 없으면 방문한다.
  for (int i = 0; i < adj.size(); ++i) {
    if (!visited[i])
      Dfs(i);
  }
}

int main() {
  adj = std::vector<std::vector<int> >(N, std::vector<int>(N, 0));
  adj[0][1] = 1;
  adj[1][2] = 1;
  adj[1][3] = 1;
  adj[2][3] = 1;

  DfsAll();
  
  return 0;
}
