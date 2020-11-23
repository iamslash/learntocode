/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

// 12ms 98.21% 9.4MB 71.59%
// dynamic programming top to bottom
// O(N^2) O(N)
class Solution {
 public:
  std::vector<int> cheapestJump(std::vector<int>& A, int B) {
    int n = A.size();
    if (n == 0 || A[n-1] == -1)
      return {};
    
    std::vector<int> C(n, INT_MAX);  // C[i]: minimum cumulative sum of i
    std::vector<int> F(n, -1); // F[i]: from index to i
    C[n-1] = A[n-1];

    for (int i = n-2; i >= 0; --i) {
      if (A[i] == -1)
        continue;
      for (int j = i+1; j <= std::min(i+B, n-1); ++j) {
        if (C[j] == INT_MAX)
          continue;
        if (A[i] + C[j] < C[i]) {
          C[i] = A[i] + C[j];
          F[i] = j;
        }
      }
    }
    if (C[0] == INT_MAX)
      return {};
    
    // reconstruct path
    std::vector<int>  rslt;
    int i = 0;
    while (i != -1) {
      rslt.push_back(i+1);
      i = F[i];      
    }
    
    return rslt;
  }
};

int main() {
  std::vector<int> A = {1, 2, 4, -1, 2};
  int B = 2;

  Solution sln;
  auto r = sln.cheapestJump(A, B);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
