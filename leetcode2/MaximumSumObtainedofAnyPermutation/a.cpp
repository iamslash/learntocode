/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// N: 1 2 3 4 5
//    4 5 3 2
// R: 0,1 1,3

// N: 1 2 3 4 5 6
// R: 0 1

// N: 1 2 3 4 5 10
// R: 0 1 2
//      1 2 3
//      1
//    3 10 5 4 

//   R: 1,3 0,1
//   N: 1 2 3 4 5
// cnt: 1 1-1  -1
//      1 2 1 1 0
//      0 1 1 1 2

// 796ms 75.00% 96.9MB 100.00%
// sort
// O(NlgN) O(N)
#define MOD 1000000007
class Solution {
 public:
  int maxSumRangeQuery(vector<int>& N, vector<vector<int>>& R) {
    vector<int> cnt(N.size());
    for (auto& r : R) {
      cnt[r[0]] += 1;
      if (r[1] + 1 < N.size()) {
        cnt[r[1] + 1] -= 1;
      }
    }
    for (int i = 1; i < cnt.size(); ++i) {
      cnt[i] += cnt[i - 1];
    }
    sort(begin(N), end(N));
    sort(begin(cnt), end(cnt));
    int ans = 0;
    for (int i = 0; i < N.size(); ++i) {
      ans = (ans + N[i] * cnt[i]) % MOD;
    }
    return ans;
  }
};
