/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// Forward declaration of ArrayReader class.
class ArrayReader;

// 48ms 88.89% 12.3MB 31.90%
// O(lgN) O(1)
class Solution {
 public:
  int search(const ArrayReader& ar, int tgt) {
    int l = 0;
    int r = 9999;
    int m;
    while (l <= r) {
      m       = (l+r)/2;
      //printf("%d %d %d\n", l, m, r);
      int val = ar.get(m); 
      if (val == INT_MAX || tgt < val)
        r = m-1;
      else if (tgt > val)
        l = m+1;
      else 
        return m;
    }
    return -1;
  }
};

int main() {
  return 0;
}
