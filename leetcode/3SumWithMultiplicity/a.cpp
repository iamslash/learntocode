/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

//   
// 1 1 2 2 3 3 4 4 5 5
//
// 1 2 3 4 5
// 3 2 2 2 2

// 4ms 99.86% 8.8MB 88.74%
// O(N^2) O(N)
#define MOD 1000000007
class Solution {
 public:
  int threeSumMulti(std::vector<int>& A, int T) {
    //
    int64_t ans = 0, n = A.size();
    std::vector<int64_t> M(101, 0);
    for (int a : A)
      M[a]++;
    for (int a = 0; a <= T; ++a) {
      for (int b = a; b <= T; ++b) {
        int c = T - a - b;
        if (c < 0 || c > 100 || c < b)
          continue;
        if (M[a] == 0 || M[b] == 0 || M[c] == 0)
          continue;
        // compare
        if (a == b && b == c) {
          ans += M[a] * (M[a] - 1) * (M[a] - 2) / 6;
        } else if (a < b && b < c) {
          ans += M[a] * M[b] * M[c];
        } else if (a == b && b < c) {
          ans += M[a] * (M[a] - 1) / 2 * M[c];
        } else if (a < b && b == c) {
          ans += M[b] * (M[b] - 1) / 2 * M[a];
        } else if (a == c && b < c) {
          ans += M[a] * (M[a] - 1) / 2 * M[b];
        }
        ans %= MOD;
      }
    }
    return ans;
  }
};

int main() {

  std::vector<int> A = {1,1,2,2,3,3,4,4,5,5};
  int T = 8;

  Solution sln;
  printf("%d\n", sln.threeSumMulti(A, T));
  
  return 0;
}
