// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/LOAN

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

using namespace std;

int N, K;
int L[5000], M[5000], G[5000];

// dist지점까지 가면서 K개 이상의 표지판을 만날 수 있는가?
bool decision(int dist) {
  int r = 0;

  for (int i=0; i < N; i++) {
    if (dist >= L[i] - M[i])
      r += (min(dist, L[i]) - (L[i] - M[i])) / G[i] + 1;
  }
  return r >= K;
}

int optimize() {
  int lo = -1;
  int hi = 8030001;

  while (lo+1 < hi) {
    int mid = (lo + hi) / 2;
    if (decision(mid))
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  for (int t=0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i=0; i < N; i++) {
      scanf("%d", &L[i]);
      scanf("%d", &M[i]);
      scanf("%d", &G[i]);
    }
    printf("%d\n", optimize());
  }

  return 0;
}
