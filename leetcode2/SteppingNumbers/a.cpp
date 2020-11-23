/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>

// 72ms 32.26% 19MB 100.00%
// BFS
// O(lg10H) O(lg10H)
class Solution {
 public:
  std::vector<int> countSteppingNumbers(int L, int H) {
    std::vector<int> rslt;
    if (L > H)
      return rslt;
    std::queue<int64_t> bfsq;
    if (L == 0)
      rslt.push_back(0);
    for (int i = 1; i < 10; i++)
      bfsq.push(i);
    while (bfsq.size()) {
      int64_t u = bfsq.front(); bfsq.pop();
      if (u < H) {
        int64_t last = u % 10;
        if (last > 0)
          bfsq.push(u * 10 + last - 1);
        if (last < 9)
          bfsq.push(u * 10 + last + 1);
      }
      if (u >= L && u <= H)
        rslt.push_back(u);
    }
    return rslt;
  }
};

int main() {
  return 0;
}
