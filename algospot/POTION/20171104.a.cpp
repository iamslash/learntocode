// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/POTION

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

int max(int a, int b) {
  return a > b ? a : b;
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int ceil(int a, int b) {
  return (a + b -1) / b;
}

std::vector<int> solve(const std::vector<int>& recipe,
                       const std::vector<int>& put) {
  int n = recipe.size();
  int b = recipe[0];
  for (int i=1; i < n; ++i) {
    b = gcd(b, recipe[i]);
  }
  int a = b;
  for (int i=0; i < n; ++i) {
    a = max(a, ceil(put[i] * b, recipe[i]));
  }
  std::vector<int> r(n);

  for (int i=0; i < n; ++i) {
    r[i] = recipe[i] * a / b - put[i];
  }
  
  return r;
  
}

void print_need(const std::vector<int>& recipe,
                       const std::vector<int>& put) {
  std::vector<int> need = solve(recipe, put);
  //
  for (int i=0; i < need.size() ; i++) {
    printf("%d ", need[i]);
  }

  printf("\n");
}

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
