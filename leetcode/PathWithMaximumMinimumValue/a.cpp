/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

// 5 4 5
// 1 2 6
// 7 4 6

// 324ms 60.60% 20.3MB 50.00%
// dijkstra
// O(N) O(N)
class Solution {
 public:
  int maximumMinimumPath(std::vector<std::vector<int>>& A) {
    int h = A.size(), w = A[0].size(), ans = A[0][0];
    int delta[5] = {-1, 0, 1, 0, -1};
    std::priority_queue<std::tuple<int, int, int>> pq;
    pq.push({A[0][0], 0, 0});
    A[0][0] = -1;
    while (pq.size()) {
      auto t = pq.top(); pq.pop();
      int d = std::get<0>(t);
      int y = std::get<1>(t);
      int x = std::get<2>(t);
      ans = std::min(ans, d);
      if (y == h-1 && x == w-1)
        return ans;
      for (int i = 0; i < 4; ++i) {
        int ny = y + delta[i];
        int nx = x + delta[i+1];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w ||
            A[ny][nx] < 0)
          continue;
        pq.push({A[ny][nx], ny, nx});
        A[ny][nx] = -1;
      }
    }
    return -1;
  }
};

int main() {
  return 0;
}
