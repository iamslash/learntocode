/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/google/59/array-and-strings/339/

#include <cstdio>
#include <vector>
#include <algorithm>


// 1 2 3
// 1 2 4
class Solution {
public:
  std::vector<int> plusOne(std::vector<int>& a) {
    std::reverse(a.begin(), a.end());
    int c = 0; // carry 
    for (int i = 0; i < a.size(); ++i) {
      a[i] = a[i] + c + 1;
      if (a[i] > 9)
        c = 1;
      a[i] %= 10;
    }
    if (c > 0)
      a.push_back(1);
    std::reverse(a.begin(), a.end());
    return a;
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
