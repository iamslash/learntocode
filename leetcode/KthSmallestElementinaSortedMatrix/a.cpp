/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 28ms 76.54%
class Solution {
 public:
  int kthSmallest(std::vector<std::vector<int>>& M, int k) {
    int n = M.size();
    int vl = M[0][0];
    int vh = M[n-1][n-1];
    int vm = 0;
    while (vl < vh) {
      vm = (vl + vh) / 2;
      int ord = 0;
      for (int i = 0; i < n; ++i) {
        int pos = std::upper_bound(
            M[i].begin(), M[i].end(), vm) -
            M[i].begin();
        ord += pos;
      }
      if (ord < k)
        vl = vm + 1;
      else
        vh = vm;
    }
    return vl;
  }
};

int main() {

  std::vector<std::vector<int>> M = {
    { 1,  5,  9},
    {10, 11, 13},
    {12, 13, 15}
  };
  int k = 8;

  Solution sln;
  printf("%d\n", sln.kthSmallest(M, k));
  return 0;
}
