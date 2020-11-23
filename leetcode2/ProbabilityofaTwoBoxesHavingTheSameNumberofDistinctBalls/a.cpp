/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// 260ms 32.81% 6.7MB 55.86%
// dynamic programming
// O(?) O(?)
class Solution {
 private:
  int sum = 0;
  double perm(vector<int>& A) {
    double ans = 1.0;
    for (int i = 0, j = 1; i < A.size(); ++i) {
      for (int k = 1; k <= A[i]; ++k, ++j)
        ans = ans * j / k;
    }
    return ans;
  }
  double dfs(vector<int>& B, vector<int>& a, vector<int>& b,
             int i, int sumA, int sumB) {    
    // printf("B.size(): %d, i: %d, sumA: %d, sumB: %d\n", B.size(), i, sumA, sumB);
    // base
    if (sumA > sum/2 || sumB > sum/2)
      return 0;
    if (i == B.size()) {
      int uniqCntA = count_if(a.begin(), a.end(), [](int n){return n > 0;});
      int uniqCntB = count_if(b.begin(), b.end(), [](int n){return n > 0;});
      if (uniqCntA != uniqCntB)
        return 0;
      return perm(a) * perm(b);
    }
    // recursion
    double ans = 0;
    for (int j = 0; j <= B[i]; ++j) {
      a[i] = j;
      b[i] = B[i] - j;
      ans += dfs(B, a, b, i+1, sumA+a[i], sumB+b[i]);
    }
    return ans;
  }
 public:
  double getProbability(vector<int>& B) {
    sum = accumulate(B.begin(), B.end(), 0);
    vector<int> a(B.size(), 0);
    vector<int> b(B.size(), 0);
    return dfs(B, a, b, 0, 0, 0) / perm(B);
  }
};
