/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// i
// 3 5
// j

//            i
// A: 0 3 6 7 7
// x: 5 4 3 2 1

//    i
// A: 3 5
// x: 2 1

// 4ms 89.20% 8.5MB 84.34%
// sort, two pointers
// O(NlgN) O(1)
class Solution {
 public:
  int specialArray(vector<int>& A) {
    int n = A.size();
    sort(A.begin(), A.end());
    for (int i = 0; i < n; ++i) {
      int x = n - i;
      if ((i == 0 && 0 < x && x <= A[i]) ||
          (i > 0 && A[i-1] < x && x <= A[i])) {
        return x;
      }
    }
    return -1;
  }
};

//         i
//    A: 3 5
//    x: 2 1
// cnts: 3 5
//       1 1

// 4ms 89.20% 8.7MB 13.33%
// bucket sort
// O(N) O(N)
class Solution {
 public:
  int specialArray(vector<int>& A) {
    vector<int> cnts(102);
    for (int a : A) {
      a = min(100, a);
      ++cnts[a];
    }
    for (int a = 100; a > 0; --a) {
      cnts[a] = cnts[a+1] + cnts[a];
      if (cnts[a] == a)
        return a;
    }
    return -1;
  }
};
