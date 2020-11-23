// Copyright (C) 2018 by iamslash

// https://www.hackerrank.com/challenges/taras-beautiful-permutations/problem

#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

const int MOD = 1000000007;
// CACHE[i][j][k] =
//   i = count of one occurrence
//   j = count of two occurrence
//   k = whether decreased number is from i or j
int64_t CACHE[2000][2000][2];

int N;

int64_t solve(int lv, int one, int two, int flag) {
  for (int i = 0; i < lv; ++i)
    printf("_");
  // base condition
  if (one == 0 && two == 0) {
    int a = (flag == 0);
    printf("%d %d %d : %d\n", one, two, flag, a);
    return a;
  } else if (one < 0 || two < 0) {
    printf("%d %d %d : 0\n", one, two, flag);
    return 0;
  }
  // memoization
  int64_t& r = CACHE[one][two][flag];
  if (r != -1) {
    printf("%d %d %d : %d\n", one, two, flag, r);
    return r;
  }
  printf("%d %d %d\n", one, two, flag);
  // recursion
  int64_t c = (flag == 1) ? (one - 1) : one;
  int64_t a = solve(lv+1, one - 1, two, 0) * c % MOD;
  int64_t b = solve(lv+1, one + 1, two - 1, 1) * two % MOD;
  r = (a + b) % MOD;
  for (int i = 0; i < lv; ++i)
    printf("_");  
  printf(": %d\n", r);
  return r;
}

int main() {
  for (int i = 0; i < 2000; ++i) {
    for (int j = 0; j < 2000; ++j) {
      CACHE[i][j][0] = CACHE[i][j][1] = -1;
    }
  }

  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> A;
    for (int i = 0; i < N; ++i) {
      int a;
      scanf("%d", &a);
      A.push_back(a);
    }
    std::sort(A.begin(), A.end());
    int one = 0;
    int two = 0;
    for (int i = 0; i < N;) {
      if (i == N - 1 || A[i] != A[i+1]) {
        one++;
        i += 1;
      } else {
        two++;
        i += 2;
      }
    }
    printf("%lld\n", solve(0, one, two, 0));
  }
  return 0;
}
