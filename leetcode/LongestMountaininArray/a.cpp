/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 20ms 95.85% 9.9MB 80.73
// two point limit
// O(N) O(1)
class Solution {
 public:
  int longestMountain(std::vector<int>& A) {
    int i = 0, j = 0, n = A.size(), ans = 0;
    // no mountain top
    if (n < 3)
      return 0;

    while (i < n - 2) {
      // skip same height
      while (i < n-1 && A[i] >= A[i+1])
        ++i;
      // climb up
      j = i + 1;
      while (j < n-1 && A[j] < A[j+1])
        ++j;
      // down
      while (j < n-1 && A[j] > A[j+1]) {
        ++j;
        // update ans
        ans = std::max(ans, j - i + 1);
      }
      i = j;
    }
    return ans;
  }
};

int main() {

  // std::vector<int> A = {2, 1, 4, 7, 3, 2, 5};
  std::vector<int> A = {1, 2, 2, 2};

  Solution sln;
  printf("%d\n", sln.longestMountain(A));
  
  return 0;
}
