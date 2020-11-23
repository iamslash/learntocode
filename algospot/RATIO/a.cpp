// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/RATIO

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

int64_t N, M;

int64_t  L = 2000000000;

int ratio(int64_t  b, int64_t  a) {
  return (a * 100) / b;
}

int needed_games(int64_t  games, int64_t  won) {
  //
  if (ratio(games, won) == ratio(games + L, won + L))
    return -1;

  //
  int64_t  lo = 0, hi = L;

  // loop variant :
  // 1. lo 게임 이기면 승률은 변하지 않는다.
  // 2. hi 게임 이기면 승률은 변한다.
  while (lo + 1 < hi) {
    int64_t mid = (lo + hi) / 2;

    if (ratio(games, won) == ratio(games+mid, won+mid))
      lo = mid;
    else
      hi = mid;
  }

  return hi;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  for (int t=0; t < T; ++t) {
    scanf("%lld", &N);
    scanf("%lld", &M);

    // printf("%d ", ratio(100, 20));
    // printf("%d\n", ratio(100, 21));

    printf("%d\n", needed_games(N, M));
  }

  return 0;
}
