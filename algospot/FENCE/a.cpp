// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/FENCE

#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

int N;

int solve(const std::vector<int>& h) {
  int maxarea = 0;
  std::stack<int> s;
  s.push(0);
  for (int r = 1; r < h.size(); ++r) {
    while (h[s.top()] > h[r]) {
      int i = s.top(); s.pop();
      int l = s.top();
      maxarea = std::max(maxarea, h[i] * (r - l - 1));
    }
    s.push(r);
  }
  return maxarea;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> h(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &h[i]);
    }
    h.insert(h.begin(), -1);
    h.push_back(0);
    printf("%d\n", solve(h));
  }
  
  return 0;
}
