/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

//    S: 2
//               i
//    A: 1 0 1 0 1
// psum: 3
// rslt: 4
//  ump: 0 1 2 3  
//       1 2 2 1

// 56ms 43.84% 19.6MB 14.80%
// O(N) O(N)
class Solution {
 public:
  int numSubarraysWithSum(std::vector<int>& A, int S) {
    std::unordered_map<int, int> ump({{0, 1}});
    int psum = 0, rslt = 0;
    for (int a : A) {
      psum += a;
      rslt += ump[psum - S];
      ump[psum]++;
      printf("a: %d, psum: %d, rslt: %d, ump[%d]: %d\n",
             a, psum, rslt, psum, ump[psum]);
    }
    return rslt;
  }
};

int main() {
  // std::vector<int> A = {1, 0, 1, 0, 1};
  // int S = 2;
  // std::vector<int> A = {0, 0, 0, 0, 0};
  // int S = 0;
  std::vector<int> A = {1, 0};
  int S = 2;

  Solution sln;
  printf("%d\n", sln.numSubarraysWithSum(A, S));
  
  
  return 0;
}
