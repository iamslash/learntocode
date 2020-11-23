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
std::vector<int> discovered;
// 지금까지 발견한 정점의 수
int counter = 0;
// 각 정점이 절단점인지 여부를 저장한다. false로 초기화한다.
std::vector<bool> is_cut_vertex;

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
}

void PrintVBool(const std::vector<bool>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
}

// here를 루트로 하는 서브트리에 있는 절단점들을 찾는다.  반환 값은
// 해당 서브트리에서 역방향 간선으로 갈 수 있는 정점 중 가장 일찍
// 발견된 정점의 발견 시점, 처음 호출할 때는 is_root=tree로 둔다.
int FindCutVertex(int here, bool is_root) {
  // 발견 순서를 기록한다.
  discovered[here] = counter++;
  int r = discovered[here];

  // 루트인 경우의 절단점 판정을 위해 자손 서브트리의 개수를 센다.
  int children = 0;
  for (int i = 0; i < adj[here].size(); ++i) {    
    int there = i;

    if (adj[here][there] == 0)
      continue;
    
    if (discovered[there] == -1) {
      ++children;
      // 이 서브트리에서 갈 수 있는 가장 높은 정점의 번호
      int subtree = FindCutVertex(there, false);
      // 그 번호가 자기 자신 이하라면 현재 위치는 절단점
      if (!is_root && subtree >= discovered[here])
        is_cut_vertex[here] = true;
      r = std::min(r, subtree);

    } else {
      r = std::min(r, discovered[there]);
    }
  }

  if (is_root)
    is_cut_vertex[here] = (children >= 2);

  return r;
      
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
  is_cut_vertex = std::vector<bool>(N, false);

  FindCutVertex(0, true);

  PrintVBool(is_cut_vertex);
  
  return 0;
}
