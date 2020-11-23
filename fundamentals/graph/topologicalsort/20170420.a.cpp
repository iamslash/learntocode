// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <algorithm>

int N = 5;

// 그래프의 인접 행렬
// adj[i][j] = i와 j사이의 간선의 수
std::vector<std::vector<int> > adj;
std::vector<bool> visited;
// for topological sort
// std::vector<int> seen;
std::vector<int> order;

// 무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
// 결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다.
void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void Dfs(int here) {
  // std::cout << "DFS visits " << here << endl;
  // printf("DFS visits %d\n", here);
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
  order.push_back(here);
}

// 서로 연결되지 않은 graph까지 탐색한다.
void DfsAll() {
  // 모든 정점을 순회하면서, 아직 방문한 적 없으면 방문한다.
  for (int i = 0; i < adj.size(); ++i) {
    if (!visited[i])
      Dfs(i);
  }
}

std::vector<int> TopologicalSort() {
  int n = adj.size();
  // seen = std::vector<int>(n, 0);
  order.clear();
  for (int i = 0; i < n; ++i)
    if (visited[i] == false)
      Dfs(i);
  std::reverse(order.begin(), order.end());

  // PrintVInt(order);

  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      if (order.size() > i && order.size() > j && adj[order[j]][order[i]] > 0)
        return std::vector<int>();

  return order;
}

int main() {
    adj = std::vector<std::vector<int> >(N, std::vector<int>(N, 0));
    // visited 를 모두 false로 초기화한다.
    visited = std::vector<bool>(N, false);

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[1][3] = 1;
    adj[2][3] = 1;
    adj[2][3] = 1;

    std::vector<int> c = TopologicalSort();
    PrintVInt(c);
  //
  return 0;
}
