/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//   0 1 2 3 2 1
// 0 0 0 0 0 0 0
// 3 0 0 0 1 0 0   
// 2 0 0 1 0 2 0
// 1 0 1 0 0 0 3
// 4 0 0 0 0 0 0
// 7 0 0 0 0 0 0

//   0 0 1 1 1 1
// 0 0 0 0 0 0 0
// 1 0 0 1 1 1 1
// 0 0 1 0 0 0 0
// 1 0 1 2 1 1 1
// 0 0 1 0 0 0 0
// 1 0 0 2 1 1 1

// 148ms 94.24% 9.4MB 91.25%
// dynamic programming
// O(AB) O(B)
class Solution {
 public:
  int findLength(std::vector<int>& A, std::vector<int>& B) {
    int h = A.size();
    int w = B.size();
    std::vector<int> C(w+1, 0);
    int r = 0;
    for (int y = 1; y <= h; ++y) {
      int prev = 0;
      C[0] = 0;
      for (int x = 1; x <= w; ++x) {
        int tmp = C[x];
        C[x] = A[y-1] == B[x-1] ?
            prev + 1 :
            0;
        prev = tmp;
        r = std::max(r, C[x]);
      }
    }
    return r;
  }
};

int main() {

  std::vector<int> A = {1, 2, 3, 2, 1};
  std::vector<int> B = {3, 2, 1, 4, 7};
  // std::vector<int> A = {0, 1, 1, 1, 1};
  // std::vector<int> B = {1, 0, 1, 0, 1};

  Solution sln;
  printf("%d\n", sln.findLength(A, B));
  
  return 0;
}
