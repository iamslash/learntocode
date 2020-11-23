/* Copyright (C) 2016 by iamslash */

#include <stdio.h>
#include <memory.h>
#include <assert.h>

#define max(a, b) a > b ? a : b;

int CACHE[1000000];

int cycle_len(int n) {
  // base condition
  if (n == 1)
    return 1;

  // memoization
  int* r = &CACHE[n];
  if (*r > 0)
    return *r;

  *r = 1;  
  // recursion
  if (n % 2 == 0) {
    *r += cycle_len(n / 2);
  } else {
    *r += cycle_len(n * 3 + 1);
  }
  //
  return *r;
}

int main() {
  int I, J;
  while (scanf("%d %d", &I, &J) != EOF) {
    memset(CACHE, -1, sizeof(CACHE));
    int m = 0;
    for (int i = I; i <= J; ++i) {
      m = max(m, cycle_len(i));
    }
    printf("%d %d %d\n", I, J, m);
  }

  return 0;
}
