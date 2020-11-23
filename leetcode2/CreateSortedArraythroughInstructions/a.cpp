/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 488ms 79.51% 143.6MB 5.43%
// binary indexed tree
// O(NlgN) O(N)
#define MOD 1000000007
class Solution {
 public:
  vector<int> data = vector<int>(100001);
  int createSortedArray(vector<int>& A) {
    int n = A.size(), ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = (ans + min(sum(A[i]-1), i - sum(A[i]))) % MOD;
      add(A[i]);
    }
    return ans;
  }
  int lsb(int x) {
    return x & -x;
  }
  void add(int x) {
    while (x < 100001) {
      data[x]++;
      x += lsb(x);
    }
  }
  int sum(int x) {
    int ans = 0;
    while (x > 0) {
      ans += data[x];
      x -= lsb(x);
    }
    return ans;
  }
};
