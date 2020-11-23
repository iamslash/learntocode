/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>

// 0 1 2 3 4
// 0 4 3 2 2

// cnt: 11
// sum: 24
// min: 1
// max: 4
// mea: sum/cnt = (1*4 + 2*3 + 3*2 + 4*2)/11 = 24/11 = 2.18182
// mod: 1
//  m1: (cnt + 1) / 2 = 12 / 2 = 6
//  m2: 6 (same with m1 because cnt is odd)
// med: 2

// 4ms 83.91% 8.7MB 100.00%
// brute force
// O(NlgN) O(1)
class Solution {
 public:
  std::vector<double> sampleStats(std::vector<int>& A) {
    double smin = 255; // min
    double smax = 0;   // max
    double smea = 0;       // mean
    double smed = 0;       // median
    double smod = 0;       // mode
    int totcnt = std::accumulate(A.begin(), A.end(), 0);
    double sum = 0, maxcnt = 0;    // max
    int m1 = (totcnt+1) / 2, m2 = totcnt % 2 ? m1 : (m1+1);
    for (int i = 0, prvcnt = 0; i < A.size(); prvcnt += A[i++]) {
      if (A[i]) {
        smin = std::min<double>(smin, i);
        smax = std::max<double>(smax, i);
        sum += (double)i * A[i];

        if (prvcnt < m1 && prvcnt + A[i] >= m1)
          smed += (double)i / 2;
        if (prvcnt < m2 && prvcnt + A[i] >= m2)
          smed += (double)i / 2;

        if (maxcnt < A[i]) {
          maxcnt = A[i];
          smod = i;
        }
      }
      smea = (double)sum / totcnt;
    }
    return {smin, smax, smea, smed, smod};
  }
};

int main() {

  
  
  return 0;
}
