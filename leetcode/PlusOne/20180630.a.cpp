/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& d) {
    if (d.size() == 0)
      return d;
    int n = d.size();
    std::reverse(d.begin(), d.end());
    int c = (d[0] + 1) / 10;
    d[0] = (d[0] + 1) % 10;
    for (int i = 1; i < n; ++i) {
      int t = (d[i] + c) / 10;
      d[i] = (d[i] + c) % 10;
      c = t;
    }
    if (c > 0)
      d.push_back(1);
    std::reverse(d.begin(), d.end());
    return d;
  }
}; 

int main() {
  Solution s;
  std::vector<int> v = {0};
  std::vector<int> r = s.plusOne(v);
  for (int e : r) {
    printf("%d ", e);
  }
  printf("\n");
  return 0;
}
