/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

// 12ms 100% 9.6MB 82.08%
// brute force
// O(N^3lgN) O(N)
class Solution {
 private:
  int64_t distSq(int x1, int y1, int x2, int y2) {
    int64_t dx = x1 - x2;
    int64_t dy = y1 - y2;
    return dx * dx + dy * dy;
  }
  int64_t dot(int x1, int y1, int x2, int y2) {
    return x1 * x2 + y1 * y2;
  }
  int64_t dot(std::vector<int> &a,
              std::vector<int> &b,
              std::vector<int> &c) {
    return dot(b[0] - a[0],
               b[1] - a[1],
               c[0] - a[0],
               c[1] - a[1]);
  }
  size_t getKey(int x, int y) {
    return (x * 40001 + y);
  }
 public:
  double minAreaFreeRect(std::vector<std::vector<int>>& P) {
    int n = P.size();
    int64_t ans = 0;
    std::unordered_set<size_t> ust;
    for (int i = 0; i < n; ++i)
      ust.insert(getKey(P[i][0], P[i][1]));
    for (int i = 0; i < n-2; ++i) {
      auto &a = P[i];
      for (int j = i+1; j < n-1; ++j) {
        auto &b = P[j];
        for (int k = j+1; k < n; ++k) {
          auto &c = P[k];
          if (dot(a, b, c) == 0) {
            int d0 = b[0] - a[0] + c[0];
            int d1 = b[1] - a[1] + c[1];
            if (ust.count(getKey(d0, d1))) {
              int64_t area  = distSq(a[0], a[1], b[0], b[1]) *
                  distSq(a[0], a[1], c[0], c[1]);
              if (ans == 0 || area < ans)
                ans = area;
            }
          }
        }
      }
    }
    return std::sqrt(ans);
  }
};

int main() {
  return 0;
}
