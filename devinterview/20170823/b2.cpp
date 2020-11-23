// Copyright (C) 2017 by iamslash

//
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the
// length is 4.
// Note that there may be more than one LIS combination, it is only
// necessary for you to return the length.

// build : g++ b2.cpp -std=c++11 -o b2.exe

// Time Complexity : O(NlgN)
// Space Complexity : O(1)

#include <cstdio>
#include <vector>
#include <algorithm>

// ex.0
// 10 20 40 25 20 50 30 70 85
// 10 20 25 30 70 85

// ex.1
// 10 9 2 5 3 7 101 18
// 2 3 7 18

int solve(const std::vector<int>&& N) {
  std::vector<int> r = {-1};
  for (const auto& n : N) {
    if (r.back() < n) {
      r.push_back(n);
    } else {
      int idx = std::lower_bound(r.begin(), r.end(), n) - r.begin();
      r[idx] = n;
    }
  }
  return r.size() - 1;
}

int main() {
  printf("%d\n", solve({10, 9, 2, 5, 3, 7, 101, 18}));
  printf("%d\n", solve({10, 20, 40, 25, 20, 50, 30, 70, 85}));
  return 0;
}
