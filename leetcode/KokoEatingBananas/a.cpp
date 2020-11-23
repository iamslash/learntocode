/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 64ms 80.13% 10.3MB 46.31%
// binary search
// O(PlgP) O(1)
class Solution {
 private:
  int getCnt(std::vector<int>& P, int num) {
    int r = 0;
    for (int p : P)
      r += (p + num - 1) / num;
    return r;
  }
 public:
  int minEatingSpeed(std::vector<int>& P, int H) {
    int lo = 1, hi = 1000000009;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (getCnt(P, mi) > H)
        lo = mi + 1;
      else
        hi = mi;
    }
    return lo;
  }
};

int main() {

  // std::vector<int> P = {3, 6, 7, 11};
  // int H = 8;
  // std::vector<int> P = {30, 11, 23, 4, 20};
  // int H = 5;
  std::vector<int> P = {30, 11, 23, 4, 20};
  int H = 6;

  Solution sln;
  printf("%d\n", sln.minEatingSpeed(P, H));
  
  return 0;
}
