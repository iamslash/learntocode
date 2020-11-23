/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/96/sorting-and-searching/774/

#include <cstdio>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    if (isBadVersion(1))
      return 1;

    // binary search
    int l = 1;
    int r = n;
    while (l < r) {
      int m = l + (r - l) / 2;      
      printf("%d %d %d\n", l, m, r);
      if (isBadVersion(m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
        
    return l;
  }
};

bool isBadVersion(int version) {
  return version >= 3;
}

int main() {
  int N = 4;
  Solution s;
  printf("%d\n", s.firstBadVersion(N));
  return 0;
}
