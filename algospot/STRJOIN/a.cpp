// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/STRJOIN

#include <cstdio>
#include <vector>
#include <queue>

int N;

std::vector<int> LEN;

int solve() {
  std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
  for (int i = 0; i < LEN.size(); ++i)
    pq.push(LEN[i]); 
  int r = 0;
  while (pq.size() > 1) {
    int min_1 = pq.top();
    pq.pop();
    int min_2 = pq.top();
    pq.pop();
    int min_sum = min_1 + min_2;
    pq.push(min_sum);
    r += min_sum;
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    LEN.resize(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &LEN[i]);
    printf("%d\n", solve());
  }
  return 0;
}

