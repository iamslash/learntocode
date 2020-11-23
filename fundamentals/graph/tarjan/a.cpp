// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <stack>

int N = 5;

// adj[i][j] = i와 j사이의 간선의 수
std::vector<std::vector<int> > adj;
// scc번호, 발견된 순서, dfs종료여부
std::vector<int> scc_id, discovered, finished;
// scc를 구성하는 정점을 구하는데 이용
std::stack<int> stck;
//
int scc_counter, vertex_counter = 0;

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
}

void print_v_bool(const std::vector<bool>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", static_cast<int>(v[i]));
  }
}

// u를 루트로 하는 서브 트리에서 역방향 간선이나 교차 간선을 통해
// 갈 수 있는 정점 중 최소 발견 순서를 반환한다.
int dfs_scc(int u) {
  // printf("%d\n", u);
  int minord = discovered[u] = vertex_counter++;
  // 스택에 u 를 넣는다. u 의 후손들은 모두 스택에서 u 이후에
  // 들어간다.
  stck.push(u);
  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    // printf("  %d-%d %d\n", u, v, discovered[v]);
    
    // tree edge
    if (discovered[v] == -1) {
      // printf("    @ %d-%d %d\n", u, v, discovered[v]);
      minord = std::min(minord, dfs_scc(v));
    // back edge
    } else if (discovered[v] < discovered[u] &&
               finished[v] != 1) {
      // printf("    # %d-%d %d\n", u, v, discovered[v]);
      minord = std::min(minord, discovered[v]);
    }
  }
  // u 에서 부모로 올라가는 간선을 끊어야 할지 확인한다.
  if (minord == discovered[u]) {
    // hdre를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의
    // 컴포넌트로 묶는다.
    while (true) {
      int t = stck.top(); stck.pop();
      scc_id[t] = scc_counter;
      if (t == u)
        break;
    }
    ++scc_counter;
  }
  finished[u] = 1;
  return minord;
}

// tarjan의 scc알고리즘
std::vector<int> tarjan_scc() {
  // 배열들을 전부 초기화
  scc_id = discovered = finished = std::vector<int>(adj.size(), -1);
  // 카운터 초기화
  scc_counter = vertex_counter = 0;
  // 모든 정점에 대해 Scc()호출
  for (int u = 0; u < adj.size(); ++u) {
    if (discovered[u] == -1)
      dfs_scc(u);
  }
  return scc_id;
}

int main() {
  adj = std::vector<std::vector<int> >(N, std::vector<int>());
  adj[0].push_back(2);
  adj[0].push_back(3);
  adj[1].push_back(0);
  adj[2].push_back(1);
  adj[3].push_back(4);

  std::vector<int> r = tarjan_scc();

  print_v_int(r);

  return 0;
}
