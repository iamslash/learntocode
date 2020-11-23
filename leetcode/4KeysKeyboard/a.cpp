/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//   C
// 0 0 
// 1 1
// 2 2 
// 3 3 
// 4 4 
// 5 5 
// 6 6 
// 7 7 
// 8 8 

// 4ms 98,73% 8.7MB 20.00%
// dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int maxA(int N) {
    std::vector<int> C(N+1);
    for (int i = 0; i <= N; ++i) {
      C[i] = i;
      for (int j = 1; j <= i - 3; ++j) {
        C[i] = std::max(C[i], C[j] * (i - j - 1));
      }
    }
    return C[N];
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.maxA(3));
  
  return 0;
}
