/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//   K: 0
//                i
//   A: 1 1 1 0 0 0 1 1 1 1 0
//                            j    
// ans: 6


//   K: 0
//        i
//   A: 0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1
//                  j
// ans: 5

// 60ms 67.21% 13.8MB 53.99%
// two pointers
// O(N) O(1)
class Solution {
 public:
  int longestOnes(std::vector<int>& A, int K) {
    int i = 0, j = 0, ans = 0, z = 0, n = A.size();
    while (j < n) {
      if (A[j++] == 0)
        z++;
      while (z > K) {
        if (A[i++] == 0)
          z--;
      }
      ans = std::max(ans, j - i);
    }
    return ans;
  }
};

int main() {
  
  std::vector<int> A = {0,0,1,1,1,0,0};
  int K = 0;
  
  Solution sln;
  printf("%d\n", sln.longestOnes(A, K));
  
  return 0;
}
