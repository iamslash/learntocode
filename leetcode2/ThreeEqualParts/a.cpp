/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//
//          i
//              j
//       A: 1 0 1 0 1
//                  k
// oneIdxs: 0 2 4 

// 
// 88ms 88.85% 40MB 23.74%
// O(N) O(N)
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
      vector<int> oneIdxs;
      int n = A.size();
      for (int i = 0; i < n; ++i) {
        if (A[i] == 1) {
          oneIdxs.push_back(i);
        }
      }
      if (oneIdxs.size() == 0)
        return vector<int>{0, 2};
      if (oneIdxs.size() % 3 != 0)
        return {-1, -1};
      int len = n - oneIdxs[oneIdxs.size() / 3 * 2];
      int i = oneIdxs[0];
      int j = oneIdxs[oneIdxs.size() / 3];
      int k = oneIdxs[oneIdxs.size() / 3 * 2];
      for (int m = 0; m < len; ++m) {
        if (A[i+m] != A[j+m] ||
            A[i+m] != A[k+m]) {
          return vector<int>{-1, -1};
        }
      }
      return vector<int>{i + len - 1, j + len};
    }
};
