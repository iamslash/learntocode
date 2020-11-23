// Copyright (C) 2017 by iamslash

// Eight Queens: Write an algorithm to print all ways of arranging
// eight queens on an 8x8 chess board so that none of them share the
// same row, column, or diagonal. In this case, "diagonal" means all
// diagonals, not just the two that bisect the board.

#include <cstdio>

const int MAXN = 100;
int N;
char BOARD[MAXN][MAXN]; // 0 1

bool is_safe(int x, int y) {
  int i, j;
  // check this row on left side
  for (i = y, j = 0; j < x; ++j)
    if (BOARD[i][j])
      return false;
  // check upper diagonal on left side
  for (i = y, j = x; i >= 0 && j >= 0; --i, --j)
    if (BOARD[i][j])
      return false;
  // check lower diagonal on left side
  for (i = y, j = x; i < N && j >= 0; ++i, --j)
    if (BOARD[i][j])
      return false;
  return true;
}

// is it possible ????
bool solve(int x) {
  // base condition
  if (x >= N)
    return true;
  // recursion
  for (int y = 0; y < N; ++y) {
    if (is_safe(x, y)) {
      BOARD[y][x] = 1;
      if (solve(x + 1))
        return true;
      BOARD[y][x] = 0;
    }
  }
  return false;
}

void print_board() {
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      printf("%d ", BOARD[y][x]);
    }
    printf("\n");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    for (int i = 0; i < MAXN; ++i)
      for (int j =0; j < MAXN; ++j)
        BOARD[i][j] = 0;
    scanf("%d", &N);
    if (solve(0))
      print_board();
    else
      printf("not exist\n");
  }
  return 0;
}
