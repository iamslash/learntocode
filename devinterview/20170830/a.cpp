// Copyright (C) 2017 by iamslash

// Write a function to determine if any 3 integers in an array sum to
// 0. Return the first set of 3 integers found if there are such set,
// return false if no such set exists

// e.g.
// input = [6, -2, 5, -4, 9]
// output = [6.-2.-4]

// g++ a.cpp -std=c++11 -o a.exe

#include <cstdio>
#include <vector>
#include <algorithm>

// Strategy         : exhaustive search
// Time Complexity  : O(N^2)
// Space Complexity : O(1)
//
// 2^16 two to the sixteen
// {6, -2, 5, -4, 9}
// {-4, -2, 5, 6, 9}
bool solve(std::vector<int> v) {
  int l, r, sum;
  std::sort(v.begin(), v.end());
  for (int i = 0; i < v.size() - 1; ++i) {
    l = i + 1;
    r = v.size() - 1;
    while (l < r) {
      sum = v[i] + v[l] + v[r];
      if (sum == 0) {
        printf("%d %d %d\n", v[i], v[l], v[r]);
        return true;
      } else if (sum < 0) {
        ++l;
      } else {
        --r;
      }
    }
  }
  return false;
}

int main() {
  solve({6, -2, 5, -4, 9});
  return 0;
}
