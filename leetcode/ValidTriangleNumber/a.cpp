/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//       k
//     j
// i
// 2 2 3 4

// 20ms 49.93%
// 6.3MB 0.40%
// O(N^2) O(1)
class Solution {
 public:
  int triangleNumber(std::vector<int>& V) {
    int cnt = 0;
    int n = V.size();
    if (n <= 2)
      return cnt;
    std::sort(V.begin(), V.end());
    for (int k = n-1; k >= 2; --k) {
      int i = 0, j = k-1;
      while (i < j) {
        if (V[i] + V[j] > V[k]) {
          cnt += j - i;
          --j;
        } else {
          ++i;
        }
      }
    }
    return cnt;
  }
};

int main() {
  std::vector<int> V = {2, 2, 3, 4};
  Solution sln;
  printf("%d\n", sln.triangleNumber(V));  
  return 0;
}
