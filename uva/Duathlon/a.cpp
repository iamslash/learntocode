// Copyright (C) 2017 by iamslash
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=15&page=show_problem&problem=1326

#include <cstdio>
#include <vector>

double t;
std::vector<double> run_spd;
std::vector<double> cyc_spd;

double time(int i, double run_dist) {
  double cyc_dist = t - run_dist;
  return run_dist / run_spd[i] + cyc_dist / cyc_spd[i];
}

double diff_time(double run_dist) {
  int    n       = run_spd.size();
  double cheater = time(n-1, run_dist);
  double others  = time(0, run_dist);
  for (int i = 1; i < n-1; ++i) {
    others = std::min(others, time(i, run_dist));
  }
  return others - cheater;
}

double solve() {
  double lo = 0;
  double hi = t;
  for (int i = 0; i < 100; ++i) {
    double aab = (2*lo + hi) / 3;
    double abb = (lo + 2*hi) / 3;
    if (diff_time(aab) > diff_time(abb))
      hi = abb;
    else
      lo = aab;
  }
  return (lo + hi) / 2;
}

int main() {
  while (scanf("%lf", &t) != EOF) {
    int n;
    scanf("%d", &n);
    run_spd.resize(n);
    cyc_spd.resize(n);
    for (int i = 0; i < n; ++i) {
      scanf("%lf %lf", &run_spd[i], &cyc_spd[i]);
    }
// The cheater can win by 612 seconds with r = 14.29km and k = 85.71km.
// The cheater cannot win.
    printf("%.2lf\n", solve());
  }
  return 0;
}
