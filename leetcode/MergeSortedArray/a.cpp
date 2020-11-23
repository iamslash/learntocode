/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/587/

#include <cstdio>
#include <vector>
#include <algorithm>

void print_v(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++ i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

class Solution {
 public:
  void merge(std::vector<int>& a, int m,
             std::vector<int>& b, int n) {
    std::vector<int> r(m+n);
    for (int i = 0, j = 0; i < m || j < n; ) {
      if (j == n || i < m && a[i] < b[j]) {
        r[i+j] = a[i];
        ++i;
      } else {
        r[i+j] = b[j];
        ++j;
      }
    }
    a.swap(r);
  }
};

int main() {
  std::vector<int> v1 = {2, 0};
  std::vector<int> v2 = {1};
  Solution s;
  s.merge(v1, v1.size()-1, v2, v2.size());
  print_v(v1);
  return 0;
}
