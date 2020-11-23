// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/FENCE

#include <cstdio>
#include <stack>
#include <vector>

int N;

int Solve(const std::vector<int>& fence) {
  int r = 0;
  // stack for height
  std::stack<int> stck;
  stck.push(0);

  for (int i = 1; i < fence.size(); ++i) {
    while (stck.empty() == false &&
           fence[stck.top()] >= fence[i]) {
      int idx = stck.top();
      stck.pop();
      // printf(" %d %d\n", i, idx);

      // calculate area
      int left = stck.top();
      int right = i;
      int area = (right - left - 1) * fence[idx];
      r = std::max(r, area);
      // printf("  %d %d %d\n", i, idx, r);
    }
    //
    stck.push(i);
  }

  // printf("  %d\n", r);
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> fence(N, 0);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &fence[i]);
    }
    fence.insert(fence.begin(), -1);
    fence.push_back(0);
    printf("%d\n", Solve(fence));
  }

  return 0;
}

