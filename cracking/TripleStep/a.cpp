// Copyright (C) 2017 by iamslash

// Triple Step: A child is running up a staircase with n steps and can
// hop either 1 step, 2 steps, or 3 steps at a time. Implement a
// method to count how many possible ways the child can run up the
// stairs.

#include <cstdio>

const int MAX_STAIRS = 100;
int N;

int CACHE[MAX_STAIRS];

int solve(int indent, int n) {
  // for (int i = 0; i < indent; ++i)
  //   printf(" ");
  // printf("  %d\n", n);
  // base condition
  if (n <= 0)
    return 0;
  // memoization
  int& r = CACHE[n];
  if (r != -1)
    return r;
  // recursion
  r = 0;
  // base condition
  if (n == 1)
    return r = 1;
  else if (n == 2 || n == 3)
    r += 1;
  for (int step = 1; step <= 3; ++step)
    r += solve(indent++, n-step);
  // for (int i = 0; i < indent; ++i)
  //   printf(" ");
  // printf("  %d\n", r);
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < MAX_STAIRS; ++i) {
      CACHE[i] = -1;
    }
    scanf("%d", &N);
    printf("%d\n", solve(0, N));
  }
  return 0;
}
