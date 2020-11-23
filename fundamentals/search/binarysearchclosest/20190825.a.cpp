/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//         l m   h 
// 1 2 4 5 6 6 8 9

class Solution {
 private:
  int getClose(int a, int b, int c) {
    int dab = b-a, dbc = c-b;
    if (dab <= dbc)
      return a;
    return c;
  }
 public:
  int solve(std::vector<int>& A, int K) {
    int n = A.size(), l = 0, h = A.size() - 1;
    while (l < h) {
      int m = (l+h)/2;
      // printf("l: %d, m: %d, h: %d\n", l, m, h);
      if (K < A[m]) {
        if (m > 0 && A[m-1] < K)
          return getClose(A[m-1], K, A[m]);
        h = m;
      } else {
        if (m < n && K < A[m+1])
          return getClose(A[m], K, A[m+1]);
        l = m+1;
      }
    }
    return A[l];
  }
};

int main() {

  std::vector<int> A = {1, 2, 4, 5, 6, 6, 8, 9};
  int K = -1;

  Solution sln;
  printf("%d\n", sln.solve(A, K));
  
  return 0;
}
