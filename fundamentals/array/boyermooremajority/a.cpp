/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

class Solution {
 public:
  int majorityElement(std::vector<int>& v) {
    int r, c = 0;
    for (int i: v) {
      if (!c || r == i)
        r = i, c++;
      else
        c--;
      printf("i:%d r:%d c:%d\n", i, r, c);
    }
    return r;
  }
};

int main() {
  std::vector<int> v = {1, 1, 1, 3, 3, 2, 2, 3, 3, 3, 2, 3, 3};
  
  Solution s;
  printf("%d\n", s.majorityElement(v));
  
  return 0;
}
