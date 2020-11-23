/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
   
//      i
//   V: 3 4 8 16
//      j
//   C: 1 3 2  1
//   P: 0 2 3  3
// num: 3
// idx: 1

// 20ms 92.58%
class Solution {
 public:
  std::vector<int> largestDivisibleSubset(std::vector<int>& V) {
    std::sort(V.begin(), V.end());
    std::vector<int> C(V.size(), 0);  // count of maximum subset
    std::vector<int> N(V.size(), 0);  // next index of i-index in maximum subset
    int num = 0;  // number of maximum subset
    int idx = 0;  // first idx of maimum subset

    for (int i = V.size() - 1; i >= 0; --i) {
      for (int j = i; j < V.size(); ++j) {
        if (V[j] % V[i] == 0 && C[i] < 1 + C[j]) {
          C[i] = 1 + C[j];
          N[i] = j;
          if (C[i] > num) {
            num = C[i];
            idx = i;
          }
        }
      }
    }

    std::vector<int> R;
    for (int i = 0; i < num; ++i) {
      R.push_back(V[idx]);
      idx = N[idx];
    }
                       
    return R;
  }
};

int main() {
  // std::vector<int> V = {1, 2, 3};
  // std::vector<int> V = {1, 2, 4, 8};
  std::vector<int> V = {3, 4, 16, 8};
  Solution sln;
  auto rslt = sln.largestDivisibleSubset(V);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
