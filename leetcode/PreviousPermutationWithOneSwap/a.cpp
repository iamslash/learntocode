/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 104ms 97.20% 12.7MB 100.00%
// O(N) O(1)
class Solution {
 public:
  std::vector<int> prevPermOpt1(std::vector<int>& A) {
    int n = A.size(), i = n - 2, j = n - 1;
    while (i >= 0 && A[i] <= A[i+1])
      --i;
    if (i < 0)
      return A;
    while (A[i] <= A[j])
      --j;
    while (A[j-1] == A[j])
      --j;
    std::swap(A[i], A[j]);
    return A;
  }
};

int main() {

  // std::vector<int> A = {1, 1, 3, 3};
  
  // do {
  //   for (int a : A)
  //     printf("%d", a);
  //   printf("\n");
  // } while (std::next_permutation(A.begin(), A.end()));

  std::vector<int> A = {3, 1, 1, 3};

  Solution sln;
  auto r = sln.prevPermOpt1(A);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
