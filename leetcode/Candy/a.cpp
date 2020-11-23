/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

// 2 1 2 
// 1 0 2
       
// 1 2 1
// 1 2 2

// 28ms 58.85% 10.8MB 29.29%
// O(N) O(N)
class Solution {
 public:
  int candy(std::vector<int>& R) {
    int n = R.size();
    if (n <= 1)
      return n;
    std::vector<int> cnt(n, 1);
    for (int i = 1; i < n; ++i) {
      if (R[i] > R[i-1])
        cnt[i] = cnt[i-1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
      if (R[i] > R[i+1])
        cnt[i] = std::max(cnt[i+1] + 1, cnt[i]);
    }
    return std::accumulate(cnt.begin(), cnt.end(), 0);
  }
};

int main() {

  // std::vector<int> R = {1, 0, 2};
  // std::vector<int> R = {1, 2, 2};
  std::vector<int> R = {1, 2, 2, 5, 6, 1, 9};
  Solution sln;
  printf("%d\n", sln.candy(R));  
  return 0;
}
