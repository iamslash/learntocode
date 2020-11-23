// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/single-number-ii/description/

#include <cstdio>
#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int>& v) {
    int rslt = 0;

    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      int a = 1 << i;
      for (int j = 0; j < v.size(); ++j) {
        if (v[j] & a)
          sum++;
      }
      if (sum % 3)
        rslt |= a;
    }

    return rslt;
    
  }
};

int main() {
  std::vector<int> v = {2, 2, 2, 3};

  Solution s;
  printf("%d\n", s.singleNumber(v));
  return 0;
}
