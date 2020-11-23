// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/JOSEPHUS

#include <cstdio>
#include <vector>
#include <queue>

int N, K;

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

std::vector<int> Solve() {
  std::vector<int> r;

  // init v
  std::queue<int> q;
  for (int i = 0; i < N; ++i) {
    q.push(i);
  }
  q.pop();

  while (q.size() > 2) {
    for (int i = 0; i < K - 1; ++i) {
      q.push(q.front());
      q.pop();
    }
    q.pop();
  }

  int q0 = q.back();
  int q1 = q.front();
  
  if (q0 > q1) {
    r.push_back(q1);
    r.push_back(q0);
  } else {
    r.push_back(q0);
    r.push_back(q1);
  }
  
  return r;  
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &K);    
    std::vector<int> r = Solve();
    printf("%d %d\n", r[0]+1, r[1]+1);
    // printf("%d %d\n", r[0], r[1]);
  }
  
  return 0;
}

