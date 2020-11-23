// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <algorithm>

int solve_recur(int* C, const int* W, const int* V, int G, int N) {
  // base condition
  if (G <= 0)
    return 0;

  // memoization
  int& r = C[G];
  if (r != -1)
    return r;

  // recursion
  r = 0;
  for (int i = 0; i < N; ++i) {
    r = std::max(r, V[i] + solve_recur(C, W, V, G-W[i], N));
  }
  return r;
}

int solve_iter(const int* W, const int* V, int N, int G) {
  int C[G+1] = {0,}; // DP[i] = max sum of value of i weight 
  // for (int i = 0; i <= c; ++i) {
  //   DP[i] = 0;
  // }
  // build DP in bottom up style
  // i item is included ???
  for (int i = 0; i <= G; ++i) {
    for (int j = 0; j < N; ++j) {
      if (W[j] <= i)
        C[i] = std::max(C[i], V[j] + C[i-W[j]]);
    }
  }
  return C[G];
}

int main() {
  int V[] = {10, 30, 20};
  int W[] = {5, 10, 15};
  int G   = 100;
  int N   = 3;
  int C[101] = {-1,};

  // for (int i = 0; i < 101; ++i) {
  //   CACHE[i] = -1;
  // }
  // printf("%d\n", solve_recur(W, V, C));  
  printf("%d\n", solve_iter(W, V, N, G));
  // 300
  
  return 0;
}
