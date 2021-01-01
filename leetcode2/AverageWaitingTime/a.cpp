/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// a   a c              11
// . . . . 5 . . . . 10
//   b           b

//         a   a      c       c
// . . . . 5 . . . . 10 . . . . 15 . . . . 20 21
//         b            b                   d  d
// 2 6 4 1

// 388ms 93.36% 73.3% 50.38%
// brute force
// O(N) O(1)
class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    int n = customers.size(), last = 1;
    double sumWait = 0.0;
    for (int i = 0; i < n; ++i) {      
      int start = customers[i][0];
      if (start > last)
        last = start;
      int end = last + customers[i][1];
      sumWait += end - start;
      last = end;
    }
    return sumWait / n; 
  }
};
