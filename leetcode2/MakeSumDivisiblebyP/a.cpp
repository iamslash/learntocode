/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

// 368ms 100.00% 66.7MB 100.00%
// partial sum
// O(N) O(1)
class Solution {
 public:
  int minSubarray(vector<int>& A, int p) {
    int psn = 0, psi = 0, minLen = A.size();
    for (int a : A) {
      psn = (psn + a) % p;
    }
    if (psn == 0)
      return 0;
    unordered_map<int, int> pos = {{0, -1}};
    for (int i = 0; i < A.size(); ++i) {
      psi = (psi + A[i]) % p;
      int psj = (psi - psn + p) % p;
      if (pos.count(psj)) {
        minLen = min(minLen, i - pos[psj]);        
      }
      pos[psi] = i;
    }
    if (minLen >= A.size()) {
      return -1;
    }
    return minLen;
  }
};
