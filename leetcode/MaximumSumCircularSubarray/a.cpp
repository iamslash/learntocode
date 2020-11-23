/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//                 i
//      A: 1 -2 3 -2 
// curmax:  1
// maxsum:  3
// curmin: -2
// minsum: -2
// allsum:  0

// 92ms 64.23% 12.7MB 54.79%
// O(N) O(1)
class Solution {
 public:
  int maxSubarraySumCircular(std::vector<int>& A) {
    int allsum = 0;
    int glbmax = INT_MIN, locmax = 0;
    int glbmin = INT_MAX, locmin = 0;
    for (int a : A) {
      locmax = std::max(locmax + a, a);
      glbmax = std::max(glbmax, locmax);
      locmin = std::min(locmin + a, a);
      glbmin = std::min(glbmin, locmin);
      allsum += a;
    }
    return glbmax > 0 ?
        std::max(glbmax, allsum - glbmin) :
        glbmax;
  }
};

int main() {
  return 0;
}
