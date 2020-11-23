/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>
#include <vector>

// pv: 1
// s     e
// i     
// 5 1 1 2 0 0
//     j

// 64ms 71.29%
// O(NlgN) O(1)
class Solution {
 private:
  void solve(std::vector<int>& V, int s, int e) {
    // divide and conquor
    int i = s, j = e, pv = V[(s+e)/2];
    while (i <= j) {
      while (V[i] < pv)
        ++i;
      while (V[j] > pv)
        --j;
      if (i <= j)
        std::swap(V[i++], V[j--]);
    }
    // printf("s: %d, e: %d, i:%d, j:%d\n", s, e, i, j);
    if (s < j)
      solve(V, s, j);
    if (i < e)
      solve(V, i, e);
  }
 public:
  std::vector<int> sortArray(std::vector<int>& V) {

    // divide and conquor
    solve(V, 0, V.size()-1);    

    return V;
  }
};

int main() {

  // std::vector<int> A = {5, 2, 3, 1};
  std::vector<int> A = {5, 1, 1, 2, 0, 0};
  Solution sln;
  auto r = sln.sortArray(A);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  return 0;
}
