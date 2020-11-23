// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/FIX

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

int N;

int main() {
  int T;  // number of T
  scanf("%d", &T);
  for (int t=0; t < T; ++t) {
    scanf("%d", &N);

    int ordered_cnt = 0;
    for (int i=0; i < N; i++) {
      int n;
      scanf("%d", &n);

      if (n == i+1)
        ordered_cnt++;
    }

    printf("%d\n", ordered_cnt);
  }

  return 0;
}
