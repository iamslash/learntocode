// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/827/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>


// v: 1 2 3 4
// r: 24 12 8 6
// x: 24
//
// 2 direction multiply
class Solution {
 public:
  std::vector<int> productExceptSelf(std::vector<int>& v) {
    std::vector<int> r(v.size());
    int n = v.size();
    int x = 1;
    for (int i = 0; i < n; ++i) {
      r[i] = x;
      x *= v[i];
    }
    x = 1;
    for (int i = n-1; i >= 0; --i) {
      r[i] *= x;
      x *= v[i];
    }
    return r;
  }
};

int main() {
  std::vector<int> v = {1, 2, 3, 4};

  Solution s;
  std::vector<int> r = s.productExceptSelf(v);

  for (int a : r) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
