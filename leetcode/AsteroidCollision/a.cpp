/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 20ms 100.00% 11.2MB 68.49%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> asteroidCollision(std::vector<int>& A) {
    std::vector<int> r;
        // b > 0, a > 0
        //   b == a
        // b < 0, a > 0
        // b < 0, a < 0
        //   b == a
        
        // b > 0, a < 0
        //   b  < |a|
        //   b == |a|
        //   b  > |a|

    for (int a : A) {
      while (!r.empty() && r.back() > 0 && a < 0 && r.back() < -a)
        r.pop_back();
      if (!r.empty() && r.back() > 0 && a < 0) {
        if (r.back() == -a) {
          r.pop_back();
        }
      } else {
        r.push_back(a);
      }
    }
    return r;
  }
};

int main() {
  std::vector<int> A = {5, 10, -5};
  // std::vector<int> A = {8, -8};
  // std::vector<int> A = {10, 2, -5};
  // std::vector<int> A = {-2, -2, 1, -2};
  // std::vector<int> A = {1,-2,-2,-2};
  Solution sln;
  auto r = sln.asteroidCollision(A);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
