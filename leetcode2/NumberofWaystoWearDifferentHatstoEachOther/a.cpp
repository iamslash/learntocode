/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 32ms 83.72% 8.4MB 56.81%
// iterative dynamic programming
// O(N) O(N)
#define MOD 1000000007
class Solution {
 public:
  int numberWays(vector<vector<int>>& person2hat) {
    vector<vector<int>> hat2person(40);
    int n = person2hat.size();
    vector<int> masks(1 << n);
    masks[0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int h : person2hat[i]) {
        hat2person[h-1].push_back(i);
      }
    }
    for (int i = 0; i < 40; ++i) {
      for (int j = (1 << n) - 1; j >= 0; --j) {
        for (int p : hat2person[i]) {
          if ((j & (1 << p)) == 0) {
            masks[j | (1 << p)] += masks[j];
            masks[j | (1 << p)] %= MOD;
          }
        }
      }
    }
    return masks[(1<<n)-1];
  }
};
