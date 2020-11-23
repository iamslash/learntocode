// Copyright (C) 2016 by iamslash

// https://www.acmicpc.net/problem/1931

#include <cstdio>
#include <vector>
#include <algorithm>

int N;
std::vector<std::pair<int, int> > TIME;

int solve() {
  int r = 0;
  std::sort(TIME.begin(), TIME.end());
  int next_min_begin = 0;
  for (int i = 0; i < TIME.size(); ++i) {
    int finish = TIME[i].first;
    int begin = TIME[i].second;
    if (next_min_begin <= begin) {
      next_min_begin = finish;
      ++r;
      // printf("%d %d\n", begin, finish);
    }
  }
  return r;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int b, f;
    scanf("%d %d", &b, &f);
    TIME.push_back(std::make_pair(f, b));
  }
  printf("%d\n", solve());
  return 0;
}


