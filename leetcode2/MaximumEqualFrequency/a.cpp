/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//            i
//       A: 2 2 1 1 5 3 3 5
//  cntVec: 2
//          1
// freqVec:-1

// 104ms 97.83% 78.1MB 9.13%
// It's too difficult
// O(N) O(N)
class Solution {
 public:
  int maxEqualFreq(vector<int>& A) {
    vector<int> cntVec(100001), freqVec(100001);
    int ans = 0, n = A.size(), a, c, d;
    for (int i = 1; i <= n; ++i) {
      a = A[i-1];
      --freqVec[cntVec[a]];
      c = ++cntVec[a];
      ++freqVec[cntVec[a]];

      if (freqVec[c] * c == i && i < n)
        ans = i + 1;
      d = i - freqVec[c] * c;
      if ((d == c + 1 || d == 1) && freqVec[d] == 1)
        ans = i;            
    }
    return ans;        
  }
};
