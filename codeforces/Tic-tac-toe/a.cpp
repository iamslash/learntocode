// Copyright (C) 2017 by iamslash
// http://codeforces.com/problemset/problem/3/C

#include <cstdio>
#include <string>


// result : first, second, illegal, the first player won, the second player won
char BOARD[3][3];

int CACHE

std::string solve() {
  return "second";
}

int main() {

  int x_cnt = 0;
  int o_cnt = 0;
  for (int i = 0; i < 3; ++i)
    scanf("%s", BOARD[i]);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      printf("%c", BOARD[i][j]);
    }
    printf("\n");
  }
  
  printf("%s\n", solve().c_str());
  
  return 0;
}

