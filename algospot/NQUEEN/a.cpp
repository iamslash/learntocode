// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/NQUEEN

#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

int N;
int Q[12];
int64_t BEST = 0;

bool is_past_ok(int y, int x) {
  int i, j;
  // check upper column
  for (i = 0; i < y; ++i)
    if (Q[i] == x)
      return false;

  // check left upper diagonal
  for (i = y, j = x; i >= 0 && j >= 0; --i, --j)
    if (Q[i] == j)
      return false;

  // check right upper diagonal
  for (i = y, j = x; i >= 0 && j < N; --i, ++j)
    if (Q[i] == j)
      return false;

  return true;
}

void nqueen(int y) {
  // for (int i = 0; i < y; ++i)
  //   printf("_");
  // printf("%d\n", y);

  // base condition
  if (y >= N) {
    BEST++;
    return;
  }

  // recursion
  for (int x = 0; x < N; ++x) {
    if (is_past_ok(y, x)) {
      // for (int i = 0; i < y; ++i)
      //   printf("_");
      // printf("%d %d\n", y, x);

      Q[y] = x;
      nqueen(y+1);
      Q[y] = -1;
    }
  }
}

int64_t solve() {
  memset(Q, -1, sizeof(Q));
  BEST = 0;
  nqueen(0);
  return BEST;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    printf("%lld\n", solve());
  }
}
