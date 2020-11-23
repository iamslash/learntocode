// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/PINBALL

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
  //
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);

    std::vector<int> recipe;
    std::vector<int> put;

    for (int i=0; i < N; ++i) {
      int r;
      scanf("%d", &r);
      recipe.push_back(r);
    }
    for (int i=0; i < N; ++i) {
      int p;
      scanf("%d", &p);
      put.push_back(p);
    }

    print_need(recipe, put);
  }

  return 0;
}
