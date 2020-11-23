// Copyright (C) 2017 by iamslash

// Robot in a Grid: Imagine a robot sitting on the upper left corner
// of grid with r rows and c columns. The robot can only move in two
// directions, right and down, but certain cells are "off limits" such
// that the robot cannot step on them. Design an algorithm to find a
// path for the robot from the top left to the bottom right.

#include <cstdio>

const int MAX_N = 100+1;
int Y, X;
char BOARD[MAX_N][MAX_N];
int CACHE[MAX_N][MAX_N];

int solve(int y, int x) {
  // base condition
  if (y >= Y || x >= X)
    return 0;
  if (BOARD[y][x] == 'x')
    return 0;
  if (y == Y - 1)
    return 1;
  // memoization
  int& r = CACHE[y][x];
  if (r != -1)
    return r;
  // recursion
  r = solve(y+1, x) + solve(y, x+1);
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int y = 0; y < MAX_N; ++y)
      for (int x = 0; x < MAX_N; ++x)
        CACHE[y][x] = -1;
    scanf("%d %d", &Y, &X);
    for (int y = 0; y < Y; ++y) {
      scanf("%s", BOARD[y]);
    }
    printf("%d\n", solve(0, 0));
  }
  return 0;
}

