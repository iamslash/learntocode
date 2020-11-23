/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

// // 556ms 7.26% 9.9MB 75.86%
// // Q. G can be empty()?
// // Q. what is the range of count of '1'?
// // brute force
// // O(YXN) O(N)
// // N: count of 1
// class Solution {
//  private:
//   int dist(int a, int b, int c, int d) {
//     return std::abs(c-a) + std::abs(d-b);
//   }
//  public:
//   int minTotalDistance(std::vector<std::vector<int>>& G) {
//     std::vector<std::pair<int, int>> P;
//     for (int y = 0; y < G.size(); ++y) {
//       for (int x = 0; x < G[0].size(); ++x) {
//         if (G[y][x] == 1)
//           P.push_back({y, x});
//       }
//     }
//     int rslt = INT_MAX;
//     for (int y = 0; y < G.size(); ++y) {
//       for (int x = 0; x < G[0].size(); ++x) {
//         double sum = 0.0;
//         for (auto& pr : P)
//           sum += dist(y, x, pr.first, pr.second);
//         rslt = std::min(rslt, (int)sum);
//       }
//     }
//     return rslt == INT_MAX ? 0 : rslt;
//   }
// };

// 8ms 100.00% 10.1MB 58.62%
// O(YX) O(max(Y,X))
class Solution {
 private:
  int minDist(std::vector<int>& V) {
    std::sort(V.begin(), V.end());
    int i = 0;
    int j = V.size()-1;
    int rslt = 0;
    while (i < j)
      rslt += V[j--] - V[i++];
    return rslt;
  }
 public:
  int minTotalDistance(std::vector<std::vector<int>>& G) {
    std::vector<int> Y, X;
    for (int y = 0; y < G.size(); ++y) {
      for (int x = 0; x < G[0].size(); ++x) {
        if (G[y][x] == 1) {
          Y.push_back(y);
          X.push_back(x);
        }
      }
    }
    return minDist(Y) + minDist(X);
  }
};

int main() {
  return 0;
}
