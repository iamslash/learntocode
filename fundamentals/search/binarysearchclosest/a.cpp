/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// K: 6
//                l
// A: 1 2 4 5 6 6 8 9
//              m h
//

class Solution {
 private:
  int getClose(int a, int b, int c) {
    int dab = std::abs(b - a);
    int dbc = std::abs(c - b);
    return dab <= dbc ? a : c;
  }
 public:
  int solve(std::vector<int>& A, int K) {
    int n = A.size(), l = 0, h = n - 1, m = 0;
    while (l < h) {
      m = (l+h)/2;
      // printf("l: %d, m: %d, h: %d\n", l, m, h);
      if (K < A[m])
        h = m;
      else
        l = m + 1;
    }
    if (l == 0)
      return A[0];
    return getClose(A[l-1], K, A[l]);
  }
};

int main() {

  std::vector<int> A = {1, 2, 4, 5, 6, 6, 8, 9};
  int K = 3;

  Solution sln;
  printf("%d\n", sln.solve(A, K));
  
  return 0;
}
