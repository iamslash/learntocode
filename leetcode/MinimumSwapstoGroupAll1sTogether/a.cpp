/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// i   j    
// 1 0 1 1

// 76ms 95.55% 16.9MB 100.00%
// sliding window
// O(N) O(1)
class Solution {
 public:
  int minSwaps(std::vector<int>& A) {
    int slide = std::count_if(A.begin(), A.end(),
                              [](int a){return a == 1;});
    int i = 0, j = 0, n = A.size(), ans = 0, ocnt = 0;
    while (j < n) {
      if (j >= slide - 1)
        ocnt += A[i++] ? -1 : 0;
      ocnt += A[++j] ? 1 : 0;
      ans = std::max(ans, ocnt);
    }
    return slide - ans;
  }
};

int main() {
  return 0;
}
