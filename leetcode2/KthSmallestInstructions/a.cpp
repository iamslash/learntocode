/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

// https://maincode.tistory.com/16

// nCr = n! / r! * (n-r)!
// 5C3 = 5 * 4 * 3 / 3 * 2 *1
//     = 3 * 4 * 5 / 1 * 2 * 3
//     = 1 * 3 / 1 * 4 / 2 * 5 / 3

// 8ms 68.22% 15.6MB 5.08%
// combination
// O(N^2) O(1)
class Solution {
 private:
  int combi(int n, int r) {
    int64_t ans = 1;
    for (int i = 1, j = n - r + 1; i <= r; ++i, ++j) {
      ans = ans * j / i;
    }
    return ans;
  }
 public:
  string kthSmallestPath(vector<int>& A, int k) {
    int v = A[0], h = A[1], n = v + h;
    string s;
    for (int i = 0; i < n; ++i) {
      if (h) {
        int c = combi(h + v - 1, v);
        if (k <= c) {
          s += 'H';
          --h;
        } else {
          k -= c;
          s += 'V';
          --v;
        }
      } else {
        s += 'V';
        --v;
      }
    }
    return s;
  }
};
