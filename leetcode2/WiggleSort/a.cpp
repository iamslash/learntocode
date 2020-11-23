/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// i
// 1 2 3 4 5

// // 36ms 91.53% 10MB 10.42%
// // O(NlgN) O(N)
// class Solution {
//  public:
//   void wiggleSort(std::vector<int>& V) {
//     int n = V.size();
//     std::sort(V.begin(), V.end());
//     std::vector<int> W = V;
//     int i = 0, j = (n+1)/2;
//     for (int k = 0; k < n; ++k) 
//       V[k] = (k % 2 == 0) ? W[i++] : W[j++];
//   }
// };

void printv(std::vector<int>& V) {
  for (int i : V)
    printf("%d ", i);
  printf("\n");
}
//   i
// 3 5 2 1 6 4
// O(N) O(1)
class Solution {
 public:
  void wiggleSort(std::vector<int>& V) {
    for (int i = 1; i < V.size(); ++i) {
      if (((i&1) && V[i] < V[i-1]) || (!(i&1) && V[i-1] < V[i]))
        std::swap(V[i], V[i-1]);
      printf("%d : ", i);
      printv(V);
    }
  }
};

// 36ms 91.53% 9.7MB 60.42%
int main() {
  std::vector<int> V = {3,5,2,1,6,4};
  // std::vector<int> V = {3,5,2,1,6};
  Solution sln;
  sln.wiggleSort(V);
  for (int i : V)
    printf("%d ", i);
  printf("\n");     
  
  return 0;
}
