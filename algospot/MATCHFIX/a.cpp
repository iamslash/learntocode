// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/MATCHFIX

#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_V 200
#define MAX_I 987654321

int N, M;
int wins[20];
int match[200][2];

int V;
int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int ford_fulkerson(int source, int sink) {
}

bool can_win_with(int total_win) {
}

int solve(int from_win) {
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &wins[i]);
    }
    for (int i = 0; i < M; ++i) {
      scanf("%d %d", &match[i][0], &match[i][1]);
    }

    // init variables
    for (int i = 0; i < MAX_V; ++i) {
      for (int j = 0; j < MAX_V; ++j) {
        capacity[i][j] = 0;
        flow[i][j] = 0;
      }
    }
    V = 2 + M + N;
    printf("%d\n", solve(wins[0]));
  }

  return 0;
}
