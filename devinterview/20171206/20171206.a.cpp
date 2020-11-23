// Copyright (C) 2017 by iamslash

// https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
// http://mxwell.github.io/draw-graph/?q=digraph

// a.txt 2
// b.txt 9
// c.txt 45764845

// cases
// 0. src -> cycle && cycle -> dst  ==> cycle
// 1. src !-> cycle && cycle !-> dst
// 2. src -> cycle && cycle !-> dst
// 3. asyclic

// 0. make sure that a node is reachable from src and dst
//   fnd_src, fnd_dst
// 1. dfs all and check the cycle of the node
//   this node is visited again after dfs from src

#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 10000, MOD = 1000000000;
vector<int> adj_f[N]; // forward adjacency matrix
vector<int> adj_b[N]; // backward adjacency matrix
bool fnd_src[N]; // found from source
bool fnd_dst[N]; // found from destination
bool fnd_cnt[N];     // found for count
int n, CACHE[N];

void dfs(vector<int> adj[], bool fnd[], int u)
{
  fnd[u] = true;
  for (int v: adj[u])
    if (! fnd[v])
      dfs(adj, fnd, v);
}

int count(int u)
{
  // memoization
  if (CACHE[u] != -1)
    return CACHE[u];
  int& r = CACHE[u];

  r = 0;
  fnd_cnt[u] = true;
  if (u == n-1)
    r = 1;
  else {
    for (int v: adj_f[u])
      if (fnd_src[v] && fnd_dst[v]) {
        if (fnd_cnt[v])
          throw 0;
        r = (r + count(v)) % MOD;
      }
  }
  fnd_cnt[u] = false;
  return r;
}

int main()
{
  int m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u; --v;
    adj_f[u].push_back(v);
    adj_b[v].push_back(u);
  }
  dfs(adj_f, fnd_src, 0);
  dfs(adj_b, fnd_dst, n-1);
  fill_n(CACHE, n, -1);
  try {
    printf("%d\n", count(0));
  } catch (...) {
    puts("INFINITE PATHS");
  }
  // printf("%d\n", (~ 0) ? 1 : 0);
  // printf("%d\n", (~ 1) ? 1 : 0);
  // printf("%d\n", (~ 2) ? 1 : 0);
  // printf("%d\n", (~ -1)? 1 : 0);
}
