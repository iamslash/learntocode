// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/gray-code/description/

#include <cstdio>
#include <vector>

class Solution {
 public:
  std::vector<int> grayCode(int n) {
    std::vector<int> r;
    n = 1 << n;
    for (int i = 0; i < n; ++i) {
      r.push_back(i ^ (i >> 1));
    }
    return r;
  }
};

int main() {
  int n = 0;
  Solution s;
  auto r = s.grayCode(n);
  for (int a : r) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
