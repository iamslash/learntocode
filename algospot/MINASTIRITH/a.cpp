// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/MINASTIRITH

#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

const double PI = 2.0 * acos(0);
const int MAX_INT = 987654321;
std::vector<std::pair<double, double> > RANGES;
int N;
double Y[100], X[100], R[100];

void build_ranges() {
  for (int i = 0; i < N; ++i) {
    double loc = fmod(2 * PI + atan2(Y[i], X[i]), 2 * PI);
    double range = 2.0 * asin(R[i] / 2.0 / 8.0);
    RANGES[i] = std::make_pair(loc - range, loc + range);
  }
  std::sort(RANGES.begin(), RANGES.end());
}

// return min cnt which covers [start, end]
int solve_linear(double start, double end) {
  int used = 0;
  int idx = 0;
  while (start < end) {
    double max_from = -1;
    // find from just before start
    while (idx < N && RANGES[idx].first <= start) {
      max_from = std::max(max_from, RANGES[idx].second);
      ++idx;
    }
    if (max_from <= start)
      return MAX_INT;
    start = max_from;
    ++used;
  }
  return used;
}

int solve_circular() {
  int r = MAX_INT;
  for (int i = 0; i < N; ++i) {
    if (RANGES[i].first <= 0 || RANGES[i].second >= 2 * PI) {
      double start = fmod(RANGES[i].second, 2 * PI);
      double end = fmod(RANGES[i].first + 2 * PI, 2 * PI);
      r = std::min(r, 1 + solve_linear(start, end));
    }
  }
  return r;
}

int solve() {
  RANGES.resize(N);
  build_ranges();
  return solve_circular();
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%lf %lf %lf", &Y[i], &X[i], &R[i]);
    }
    int r = solve();
    if (r == MAX_INT)
      printf("IMPOSSIBLE");
    else 
      printf("%d\n", r);
  }
  return 0;
}
