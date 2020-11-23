// Copyright (C) 2017 by iamslash
#include <cstdio>
#include <cstdint>

int main() {
  int N, M, A;
  scanf("%d %d %d", &N, &M, &A);
  int64_t nx = N % A == 0 ? N / A : (N / A) + 1;
  int64_t ny = M % A == 0 ? M / A : (M / A) + 1;
  int64_t r = nx * ny;
  printf("%lld\n", r);
  return 0;
}
