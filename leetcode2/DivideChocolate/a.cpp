/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

// K: 3
//
// S: 1 2 5 7 9
//
// (l + r) / 2 
// l: 1
// r: 25
// m: 13
//
// (l + r + 1) / 2
// l: 1
// r: 25
// m: 13


// binary search
// O(N^2lgN) O(1)
class Solution {
 private:
  int split(vector<int>& S, int minSum) {
    int cnt = 0;
    int unitSum = 0;
    for (int sweet : S) {
      unitSum += sweet;
      if (unitSum >= minSum) {
        cnt++;
        unitSum = 0;
      }
    }
    return cnt;
  }
 public:
  int maximizeSweetness(vector<int>& S, int K) {
    K = K + 1;
    int l = *min_element(S.begin(), S.end());
    int r = accumulate(S.begin(), S.end(), 0);
    while (l < r) {
      int m = l + (r - l + 1) / 2;
      if (split(S, m) < K) {
        r = m - 1;
      } else {
        l = m;
      }
    }
    return l;
  }
};
