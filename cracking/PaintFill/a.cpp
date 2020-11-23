// Copyright (C) 2017 by iamslash

// Paint Fill: Implement the "paint fill" function that one might see
// on many image editing programs.  That is, given a screen
// (represented by a two-dimensional array of colors), a point, and a
// new color, fill in the surrounding area until the color changes
// from the original color.

#include <cstdio>

const int MAXPOS = 100;
int R, C;
char SCR[MAXPOS][MAXPOS];

void _solve(int x, int y, char old_color, char new_color) {
  // base condition
  if (x < 0 || x >= C || y < 0 || y >= R)
    return;

  // recursion
  if (SCR[y][x] == old_color) {
    SCR[y][x] = new_color;
    _solve(x, y + 1, old_color, new_color);
    _solve(x + 1, y, old_color, new_color);
    _solve(x, y - 1, old_color, new_color);
    _solve(x - 1, y, old_color, new_color);
  }
}

void solve(int x, int y, char new_color) {
  if (SCR[y][x] == new_color)
    return;
  _solve(x, y, SCR[y][x], new_color);
}

void print_scr(int r, int c) {
  for (int y = 0; y < r; ++y) {
    for (int x = 0; x < c; ++x) {
      printf("%d ", SCR[y][x]);
    }
    printf("\n");
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        char color;
        scanf("%d", &color);
        SCR[i][j] = color;
      }
    }

    int X, Y;
    char new_color;
    scanf("%d %d %d", &X, &Y, &new_color);
    solve(X, Y, new_color);
    print_scr(R, C);
  }
  
  return 0;
}
