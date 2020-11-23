/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

// sum : 33
// pre : 1
//   k : 11
//           i
//   v : 23 10
// ust : 0
// 
// 24ms 98.63%
// O(N) O(N)
class Solution {
 public:
  bool checkSubarraySum(std::vector<int>& V, int k) {
    if (k == 0) {
      for (int i = 1; i < V.size(); ++i) {
        if (V[i] == 0 && V[i-1] == 0)
          return true;
      }
      return false;
    }
    int n = V.size(), sum = 0, pre = 0;
    std::unordered_set<int> ust;
    for (int i = 0; i < n; ++i) {
      sum += V[i];
      int mod = sum % k;
      if (ust.count(mod))
        return true;
      ust.insert(pre);
      pre = mod;
    }
    return false;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  // std::vector<int> V = {23, 2, 5, 6, 7};
  // int k = 6;
  // std::vector<int> V = {23, 2};
  // int k = 6;
  std::vector<int> V = {23, 2, 6, 4, 7};
  int k = 6;

  Solution sln;
  printb(sln.checkSubarraySum(V, k));
  
  return 0;
}
