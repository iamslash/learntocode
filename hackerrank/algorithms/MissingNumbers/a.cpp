// Copyright (C) 2018 by iamslash
// https://www.hackerrank.com/challenges/missing-numbers/problem

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int N, M;

// std::map<int, int> S;


// int main() {
//   int xmax = 0;
//   int xmin = 987654321;
//   scanf("%d", &N);
//   for (int i = 0; i < N; ++i) {
//     int x;
//     scanf("%d", &x);
//     S.find(x) == S.end() ? S[x] = 1 : S[x]++;
//   }
//   scanf("%d", &M);
//   for (int i = 0; i < M; ++i) {
//     int x;
//     scanf("%d", &x);
//     S.find(x) == S.end() ? S[x] = -1 : S[x]--;
//     xmin = std::min(xmin, x);
//     xmax = std::max(xmax, x);
//   }
//   for (auto it = S.begin(); it != S.end(); ++it) {
//     if (*it.second != 0) {
//       printf("%d ", *it.first);
//     }
//   }
//   return 0;
// }

int NS[10001] = {0, };
int MS[10001] = {0, };

int main() {
  int xmax = 0;
  int xmin = 987654321;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    NS[x]++;
  }
  scanf("%d", &M);
  for (int i = 0; i < M; ++i) {
    int x;
    scanf("%d", &x);
    MS[x]++;
    xmin = std::min(xmin, x);
    xmax = std::max(xmax, x);
  }
  for (int i = xmin; i <= xmax; ++i) {
    if (NS[i] != MS[i])
      printf("%d ", i);
  }
  
  return 0;
}


