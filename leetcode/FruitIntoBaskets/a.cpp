/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

//                     i       
//    A: 3 3 3 1 2 1 1 2 3 3 4
//                             j
// cnts: 2 3 4
//       1 2 1

// 176ms 51.39% 19.9MB 50.41%
// O(N) O(N)
class Solution {
 public:
  int totalFruit(std::vector<int>& A) {
    int i, j, n = A.size();
    std::unordered_map<int, int> cnts;
    for (i = 0, j = 0; j < n; ++j) {
      cnts[A[j]]++;
      if (cnts.size() > 2) {
        if (--cnts[A[i]] == 0)
          cnts.erase(A[i]);
        ++i;
      }
    }
    return j - i;
  }
};

int main() {

  // std::vector<int> A = {1, 2, 1};
  // std::vector<int> A = {0, 1, 2, 2};
  // std::vector<int> A = {1, 2, 3, 2, 2};
  std::vector<int> A = {3,3,3,1,2,1,1,2,3,3,4};

  Solution sln;
  printf("%d\n", sln.totalFruit(A));
  
  return 0;
}
