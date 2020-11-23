/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>


//        
//          j
// H: 3 2 2 2
//      K
// V: 2

// 4ms 100.00% 8.5MB 95.65%
// Q. what is the range of H.size()? [1, 100]
// Q. what is the range of H[i]? [0, 99]
// Q. what is the range of V? [0, 2000]
// Q. What is the range of K? [0, H.size()-1]
// O(V) O(1)
class Solution {
 public:
  std::vector<int> pourWater(std::vector<int>& H, int V, int K) {
    for (int i = 0; i < V; ++i) {
      int j = K;
      while (j > 0 && H[j] >= H[j-1])
        --j;
      while (j < H.size()-1 && H[j] >= H[j+1])
        ++j;
      while (j > K && H[j] == H[j-1])
        --j;
      H[j]++;
    }
    return H;
  }
};

int main() {

  // std::vector<int> H = {1, 2, 3, 4};
  // int V = 2;
  // int K = 2;
  // std::vector<int> H = {3, 1, 3};
  // int V = 5;
  // int K = 1;
  std::vector<int> H = {1,2,3,4,3,2,1,2,3,4,3,2,1};
  int V = 2;
  int K = 5;

  Solution sln;
  auto r = sln.pourWater(H, V, K);
  for (int h : r)
    printf("%d ", h);
  printf("\n");
  
  return 0;
}
