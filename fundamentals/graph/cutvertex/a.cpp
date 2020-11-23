// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>

int N = 5;

std::vector<std::vector<int>> adj;
std::vector<int> discovered;
std::vector<bool> cutvertexes;
int counter;

// u 를 시작으로 back edge의 terminal node중
// 발견 순서가 가장 최소인 녀석을 리턴한다.
int findcutvertex(int u, bool broot) {
  discovered[u] = counter++;
  int r = discovered[u];

  // u가 root인 경우 자식 노드의 숫자를 세어서 두개 이상이어야
  // cut vertex가 될 수 있다.
  int children = 0;

  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (discovered[v] == -1) {  // tree edge
      ++children;
      int minord = findcutvertex(v, false);
      if (!broot && minord >= discovered[u])
        cutvertexes[u] = true;
      r = std::min(r, minord);
    } else {  // forward, back edge
      r = std::min(r, discovered[v]);
    }
  }

  if (broot && children >= 2)
    cutvertexes[u] = true;

  return r;
}

int main() {
  // adjacency list
  adj = std::vector<std::vector<int> >(N, std::vector<int>());
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[0].push_back(3);
  adj[1].push_back(2);
  adj[2].push_back(1);
  adj[3].push_back(1);
  adj[3].push_back(2);

  // adjacency matrix
  // adj = std::vector<std::vector<int> >(N, std::vector<int>(N, 0));
  // adj[0][1] = 1;
  // adj[0][2] = 1;
  // adj[0][3] = 1;
  // adj[1][2] = 1;
  // adj[2][1] = 1;
  // adj[3][1] = 1;
  // adj[3][2] = 1;

  discovered = std::vector<int>(N, -1);
  cutvertexes = std::vector<bool>(N, false);
  findcutvertex(0, true);

  for (bool b : cutvertexes)
    printf("%s ", b ? "t" : "f");
  printf("\n");
  
  return 0;
}
