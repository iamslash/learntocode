// Copyright (C) 2018 by iamslash


// https://practice.geeksforgeeks.org/problems/minimum-platforms/0
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/

#include <cstdio>
#include <vector>
#include <algorithm>

int N;

int solve(const std::vector<int>& a,
          const std::vector<int>& b) {

  int i = 0;
  int j = 0;
  int r = 0;
  int need = 0;

  while (i < N || j < N) {
    if (a[i] < b[j]) {
      need++;
      i++;
    } else {
      need--;
      j++;
    }
    r = std::max(r, need);
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> a(N);
    std::vector<int> b(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &a[i]);
    for (int i = 0; i < N; ++i)
      scanf("%d", &b[i]);
    printf("%d\n", solve(a, b));
  }  
  return 0;
}
