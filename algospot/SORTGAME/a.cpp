// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/SORTGAME
#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

int N;

#define MAXN 8
std::map<std::vector<int>, int> M;

void PrintVInt(const std::vector<int>& v) {
  for (const int& i : v) {
    printf("%d ", i);
  }
  printf("\n");
}

// make BFS tree for 8 numbers
void BuildBFS(int n) {
  std::vector<int> perm(n);
  for (int i = 0; i < n; ++i)
    perm[i] = i;
  std::queue<std::vector<int> > q;
  q.push(perm);
  M[perm] = 0;
  while (!q.empty()) {
    std::vector<int> here = q.front();
    q.pop();
    int cost = M[here];
    for (int i = 0; i < n; ++i) {
      for (int j = i+2; j <= n; ++j) {
        std::reverse(here.begin() + i, here.begin() + j);
        if (M.count(here) == 0) {
          M[here] = cost + 1;
          q.push(here);
        }
        std::reverse(here.begin() + i, here.begin() + j);
        // printf("  qcnt: %lu mcnt: %lu i: %d j: %d\n", q.size(), M.size(), i, j);
      }
    }
  }
}

int Solve(const std::vector<int>& v) {
  int n = v.size();
  std::vector<int> fixed(n);

  for (int i = 0; i < n; ++i) {
    int smaller = 0;
    for (int j = 0; j < n; ++j) {
      if (v[j] < v[i])
        ++smaller;
    }
    fixed[i] = smaller;
  }

  return M[fixed];
}

int main() {
  int T;
  scanf("%d", &T);

  BuildBFS(MAXN);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> v(N);
    int maxelm = -1;

    for (int i = 0; i < N; ++i) {
      scanf("%d", &v[i]);
      maxelm = std::max(maxelm, v[i]);
    }
    for (int i = N; i < 8; ++i) {
      v.push_back(++maxelm);
    }
    printf("%d\n", Solve(v));
    // PrintVInt(v);
  }

  return 0;
}


