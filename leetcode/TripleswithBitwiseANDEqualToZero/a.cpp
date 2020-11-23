/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//     k
//   j
// i
// 2 1 3

// 56ms 88.24%
// O(N^2) O(1)
class Solution {
 public:
  int countTriplets(std::vector<int>& A) {
    int n = A.size();
    int rslt = 0;
    std::vector<int> C(1 << 16, -1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int x = A[i] & A[j];
        if (C[x] == -1) {
          C[x] = 0;
          for (int k = 0; k < n; ++k) {
            if ((x & A[k]) == 0)
              C[x]++;
          }
        }
        rslt += C[x];
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<int> A = {2, 1, 3};
  Solution sln;
  printf("%d\n", sln.countTriplets(A));
  
  return 0;
}
