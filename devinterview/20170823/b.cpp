// Copyright (C) 2017 by iamslash

//
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the
// length is 4.
// Note that there may be more than one LIS combination, it is only
// necessary for you to return the length.

// build : g++ b.cpp -std=c++11 -o b.exe

#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> N = {10, 9, 2, 5, 3, 6, 101, 18};

int CACHE[100];

int _solve(int cur) {
  printf("  [%d] %d\n", cur, N[cur]);
  // memoization
  int& r = CACHE[cur];
  if (r != -1)
    return r;
  // recursion
  r = 0;
  for (int nxt = cur + 1; nxt < N.size(); ++nxt) {
    if (N[cur] < N[nxt]) {
      r = std::max(r, 1 + _solve(nxt));
    }
  }
  return r;
}

int solve() {
  int r = 0;
  for (int i = 0; i < N.size(); ++i)
    r = std::max(r, _solve(i));
  return r + 1;
}

int main() {
  for (int i = 0; i < 100; ++i)
      CACHE[i] = -1;
  printf("%d\n", solve());
  
  return 0;
}
