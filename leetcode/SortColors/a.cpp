/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/798/

#include <cstdio>
#include <vector>
#include <algorithm>

// 2, 1, 0
//
//
class Solution {
 public:
  void sortColors(std::vector<int>& N) {
    int n = N.size();
    // insert sort
    for (int i = 0; i < n; ++i) {
      for (int j = i; j > 0; --j) {
        if (N[j] < N[j-1])
          std::swap(N[j], N[j-1]);
      }
    }
  }
};

int main() {
  std::vector<int> v = {2, 0, 2, 1, 1, 0};;
  Solution s;
  s.sortColors(v);
  for (int a : v) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
