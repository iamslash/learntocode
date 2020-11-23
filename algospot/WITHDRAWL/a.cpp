// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/WITHDRAWAL
// g++ -std=c++11 -o a.exe a.cpp

#include <cstdio>
#include <vector>

int N, K;
int C[1000], R[1000];

// 3 2
// 1 4 6 10 10 17
// rank \sum_{}{}c_{i} - \sum_{}{}r_{i} \geq  0
bool decision(double rank) {
  std::vector<double> v;
  for (int i = 0; i < N; ++i) {
    v.push_back(rank * C[i] - R[i]);
  }
  std::sort(v.begin(), v.end());
  double r = 0;

  for (int i = N-K; i < N; ++i) {
    r += v[i];
  }

  return r >= 0;
}

double optimize() {
  double lo = -1e-10;
  double hi = 1;

  for (int i = 0; i < 100; ++i) {
    double mid = (lo + hi) / 2;
    if (decision(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  return hi;
}

double solve() {
  // K, K+1, K+2,..., N
  // 
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &R[i]);
      scanf("%d", &C[i]);
    }
    printf("%0.10lf\n", optimize());
  }
  return 0;
}
