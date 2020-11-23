/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

//   K: 0
//          i 
//   A: 1 2 3 1 2
//            j
// cnt: 1 2 3
//      0 2 1
// ans: 10

// 116ms 67.31% 22.4MB 20.00%
// hashmap
// O(N) O(N)
class Solution {
 private:
  int cntWithMostK(std::vector<int>& A, int K) {
    int n = A.size(), ans = 0;
    std::unordered_map<int, int> cnt;
    for (int i = 0, j = 0; j < n; ++j) {
      if (!cnt[A[j]]++)
        K--;
      while (K < 0) {
        if (!--cnt[A[i]])
          K++;
        i++;
      }
      ans += j - i + 1;
    }
    return ans;
  }
 public:
  int subarraysWithKDistinct(std::vector<int>& A, int K) {
    return cntWithMostK(A, K) - cntWithMostK(A, K-1);
  }
};

int main() {
  return 0;
}
