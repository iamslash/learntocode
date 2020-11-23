// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <map>

int N = 7;

std::vector<std::vector<int>> adj;
std::vector<int> found;
std::vector<std::vector<bool>> bridge;
int counter;

void print_v_bool(const std::vector<std::vector<bool> >& v) {
  for (int i = 0; i < v.size(); ++i) {
    for (int j = 0; j < v[i].size(); ++j) {
      if (v[i][j])
        printf("%d-%d\n", i, j);
    }
  }
  printf("\n");
}

// u를 시작으로 back edge의 terminal node중
// 발견 순서가 가장 최소인 녀석을 리턴한다.
// v를 루트로 하는 서브트리에서 u를 제외한
// u의 부모로 가는 back edge가 없다면
// (u, v)는 bridge이다.
int find_bridge(int u, int p) {
  // printf("  %d\n", u);
  found[u] = counter++;
  int r = found[u];

  // 자식들을 순회하자.
  for (int v : adj[u]) {
    if (v == p)
      continue;

    // tree edge만 bridge가 될 수 있다.
    if (found[v] == -1) {
      int minord = find_bridge(v, u);
      if (minord > found[u])
        bridge[u][v] = true;
      r = std::min(r, minord);
    // (u, v)는 forward, back edge이다.
    } else {
      r = std::min(r, found[v]);
    }
  }
  return r;
}

int main() {
  // adjacency list
  adj = std::vector<std::vector<int> >(N, std::vector<int>());
  // // test case 1
  // adj[0].push_back(1);
  // adj[0].push_back(2);
  // adj[1].push_back(0);
  // adj[1].push_back(2);
  // adj[1].push_back(3);
  // adj[1].push_back(4);
  // adj[1].push_back(6);
  // adj[2].push_back(0);
  // adj[2].push_back(1);
  // adj[3].push_back(1);
  // adj[3].push_back(5);
  // adj[4].push_back(1);
  // adj[4].push_back(5);
  // adj[5].push_back(3);
  // adj[5].push_back(4);
  // adj[6].push_back(1);

  // test case 2
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[0].push_back(3);
  adj[1].push_back(0);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(1);
  adj[3].push_back(0);
  adj[3].push_back(4);
  adj[4].push_back(3);

  // // test case 3
  // adj[0].push_back(1);
  // adj[1].push_back(0);
  // adj[1].push_back(2);
  // adj[2].push_back(1);
  // adj[2].push_back(3);
  // adj[3].push_back(2);

  found = std::vector<int>(N, -1);
  bridge = std::vector<std::vector<bool>>(N, std::vector<bool>(N, false));

  find_bridge(0, 0);
  print_v_bool(bridge);

  return 0;
}
