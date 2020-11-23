// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/EDITORWARS

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>

int N, M;

struct BipartiteUnionFind {
  // parent[i] = i의 부모 노드, 루트라면 i
  // rank[i] = i가 루트인 경우, i를 루트로 하는 트리의 랭크
  // enemy[i] = i가 루트인 경우, 해당 집합과 적대 관계인 집합의 루트의 번호
  // size[i] = i가 루트인 경우, 해당 집합의 크기
  std::vector<int> parent, rank, enemy, size;
  explicit BipartiteUnionFind(int n) : parent(n), rank(n, 0),
                                       enemy(n, -1), size(n, 1) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }
  int merge(int u, int v) {
    //
    if (u == -1 || v == -1)
      return std::max(u, v);
    u = find(u);
    v = find(v);
    if (u == v) return u;
    if (rank[u] > rank[v])
      std::swap(u, v);
    if (rank[u] == rank[v])
      rank[v]++;
    parent[u] = v;
    size[v] += size[u];
    return v;
  }
  bool dis(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    // 적의 적은 나의 동지
    int a = merge(u, enemy[v]);
    int b = merge(v, enemy[u]);
    enemy[a] = b;
    enemy[b] = a;
    return true;
  }

  bool ack(int u, int v) {
    u = find(u);
    v = find(v);
    if (enemy[u] == v)
      return false;
    int a = merge(u, v);
    int b = merge(enemy[u], enemy[v]);
    enemy[a] = b;
    // 두 집합 다 적대하는 집합이 없으면 b는 -1일 수도 있다.
    if (b != -1)
      enemy[b] = a;
    return true;
  }
};

// 한 파티에 올 가능성이 있는 최대 인원은???
int MaxParty(const BipartiteUnionFind& uf) {
  int r = 0;
  for (int node = 0; node < N; ++node) {
    if (uf.parent[node] == node) {
      int enemy = uf.enemy[node];
      if (enemy > node)
        continue;
      int ally_size = uf.size[node];
      int enemy_size = (enemy == -1 ? 0 : uf.size[enemy]);
      r += std::max(ally_size, enemy_size);
      // printf(" %d %d %d %d\n", node, enemy, ally_size, enemy_size);
    }
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &M);
    BipartiteUnionFind uf(N);
    int i = 0;
    for (i = 0; i < M; ++i) {
      char buf[8] = {0, };
      int a, b;
      scanf("%s %d %d", buf, &a, &b);
      if (strcmp(buf, "ACK") == 0) {
        if (uf.ack(a, b) == false)
          break;
      } else {
        if (uf.dis(a, b) == false)
          break;
      }
    }

    // printf("N[%d] M[%d] i[%d]", N, M, i);
    if (i == M)
      printf("MAX PARTY SIZE IS %d\n", MaxParty(uf));
    else
      printf("CONTRADICTION AT %d\n", i + 1);
  }
  //
  return 0;
}
