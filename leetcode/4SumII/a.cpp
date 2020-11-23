// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <unordered_map>

class Solution {
 public:
  int fourSumCount(std::vector<int>& A, std::vector<int>& B,
                   std::vector<int>& C, std::vector<int>& D) {
    int r = 0;
    std::unordered_map<int, int> m;
    for (int a : A) {
      for (int b : B) {
        m[a+b]++;
      }
    }
    for (int c : C) {
      for (int d : D) {
        if (m.count(-c-d))
          r += m[-c-d];
      }
    }
    return r;
  }
};

// A[i] + B[j] + C[k] + D[l] = 0
// A[i] + B[j] = -C[k] -D[l] 
int main() {
  std::vector<int> a = { 1,  2};
  std::vector<int> b = {-2, -1};
  std::vector<int> c = {-1,  2};
  std::vector<int> d = { 0,  2};
  
  Solution s;
  printf("%d\n", s.fourSumCount(a, b, c, d));
  return 0;
}
