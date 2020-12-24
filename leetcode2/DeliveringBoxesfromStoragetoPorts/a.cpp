/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// sliding window, iterative dynamic programming
// O(N) O(N)
#define MAXVAL 200000
class Solution {
 public:
  int boxDelivering(vector<vector<int>>& boxes,
                    int portsCount,
                    int maxBoxes,
                    int maxWeight) {
    int n = boxes.size(), need = 0, j = 0, lastJ = 0;
    vector<int> C(n+1, MAXVAL);
    C[0] = 0;
    for (int i = 0; i < n; ++i) {
    }
    return C[n];
  }
};
