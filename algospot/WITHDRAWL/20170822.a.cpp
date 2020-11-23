// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/WITHDRAWL

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

using namespace std;

int N, K;
int C[1000], R[1000];

// 결정 문제: 누적등수 average가 되도록 할 수 있나?
bool decision(double average) {
  //
  vector<double> v;
  for (int i=0 ; i < N; i++) {
    v.push_back(average * C[i] - R[i]);
  }
  sort(v.begin(), v.end());
  double sum = 0;
  for (int i=N-K; i < N; i++) {
    sum += v[i];
  }
  return sum >= 0;
}

// 최적화 문제 얻을 수 있는 최소의 누적 등수
double optimize() {
  double lo = -1e-9;
  double hi = 1;

  for (int i=0; i < 100; i++) {
    double mid = (lo + hi) / 2;
    if (decision(mid))
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  for (int t=0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &K);
    for (int i=0; i < N; i++) {
      scanf("%d", &R[i]);
      scanf("%d", &C[i]);
    }
    printf("%0.10lf\n", optimize());
  }

  return 0;
}
