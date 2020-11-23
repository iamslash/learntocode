/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

//     0  1  2  3  4
// V:  2  3  1  4  0
// s: -1  0  0  1  0

//     0  1  2  3  4
// V:  2  4  1  3  0
// s: -1 -1 -1 -1 -1

// 36ms 18.75% 11.1MB 16.67%
// O(N) O(N)
class Solution {
 public:
  int bestRotation(std::vector<int>& V) {
    int n = V.size();
    // sump[K] = sump[K-1] + delta[K]:
    std::vector<int> delta(n, 0);
    for (int i = 0; i < n; ++i)
      delta[(i - V[i] + 1 + n) % n] -= 1;
    int maxp = delta[0];
    int maxi = 0;
    for (int i = 1; i < n; ++i) {
      delta[i] += delta[i - 1] + 1;
      if (maxp < delta[i]) {
        maxi = i;
        maxp = delta[i];
      }
    }
    return maxi;
  }
};

int main() {
  // std::vector<int> V = {2, 3, 1, 4, 0};
  std::vector<int> V = {2, 4, 1, 3, 0};

  Solution sln;
  printf("%d\n", sln.bestRotation(V));
  
  return 0;
}
