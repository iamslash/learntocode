/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// V : 1 5 1 1 6 4
//     1 1 1 4 5 6
// V : 1 1 1 1 2 2 2 2

// 68ms 97.47% 11.7MB 17.07%
// O(N) O(N)
class Solution {
 public:
  void wiggleSort(std::vector<int>& V) {
    std::vector<int> U = V;
    int n = U.size();
    std::sort(U.begin(), U.end());
    for (int i = n-1, j = 0, k = i/2+1; i >= 0; --i) {
      // printf("i: %d, j: %d, k: %d, V[i]: %d\n", i, j, k, V[i]);
      V[i] = i & 1 ? U[k++] : U[j++];
    }
  }
};

int main() {

  // std::vector<int> V = {1, 5, 1, 1, 6, 4};
  // std::vector<int> V = {1, 1, 2, 1, 2, 2, 1};
  std::vector<int> V = {1, 3, 2, 2, 3, 1};
  Solution sln;
  sln.wiggleSort(V);
  for (int a : V)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
