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
std::vector<int> discovered, finished;
// 지금까지 발견한 정점의 수
int counter = 0;

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
}

void DfsSpanningTree(int here) {
  discovered[here] = counter++;
  // 모든 인접 정점을 순회하면서
  for (int i = 0; i < adj[here].size(); ++i) {
    if (adj[here][i] == 0)
      continue;
    
    int there = i;

    printf("(%d, %d) is a ", here, there);
    // 아직 방문한 적 없다면 방문한다.
    if (discovered[there] == -1) {
      printf("tree edge\n");
      DfsSpanningTree(there);
    // 만약 there가 here보다 늦게 발견됐으면 there는 here의 후손이다.
    } else if (discovered[here] < discovered[there]) {
      printf("forward edge\n");
    // 만약 DfsSpanningTree(there)가 종료되지 않았다면 here는 there의 후손이다.
    } else if (finished[there] == 0) {
      printf("back edge\n");
    // 그렇지 않으면 cross edge이다.
    } else {
      printf("cross edge\n");
    }
  }
  finished[here] = 1;
}

int main() {
  adj = std::vector<std::vector<int> >(N, std::vector<int>(N, 0));
  adj[0][1] = 1;
  adj[0][2] = 1;
  adj[0][3] = 1;
  adj[1][2] = 1;
  adj[2][1] = 1;
  adj[3][1] = 1;
  adj[3][2] = 1;
  discovered = std::vector<int>(N, -1);
  finished = std::vector<int>(N, 0);

  DfsSpanningTree(0);
  
  return 0;
}
