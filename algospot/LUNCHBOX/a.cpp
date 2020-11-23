// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/LUNCHBOX

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

int N;
std::vector<std::pair<int, int> > TIME;

int solve() {
  int r;  // total time
  int m_acc = 0; // accumulated micro-wave time
  std::sort(TIME.begin(), TIME.end(), std::greater<std::pair<int, int> >());
  for (int i = 0; i < TIME.size(); ++i) {
    int e = TIME[i].first;
    int m = TIME[i].second;
    r = std::max(r, m_acc + m + e);
    m_acc += m;
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    TIME.clear();
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      int m, e;
      scanf("%d %d", &m, &e);
      TIME.push_back(std::make_pair(e, m));
    }
    printf("%d\n", solve());
  }
  return 0;
}
