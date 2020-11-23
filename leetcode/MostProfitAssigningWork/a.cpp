/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

// // 96ms 77.61% 14.3MB 54.01%
// // O(NlgN) O(N)
// class Solution {
//  public:
//   int maxProfitAssignment(std::vector<int>& D,
//                           std::vector<int>& P,
//                           std::vector<int>& W) {
//     std::vector<std::pair<int, int>> jobs;
//     for (int i = 0; i < D.size(); ++i)
//       jobs.push_back({D[i], P[i]});
//     std::sort(jobs.begin(), jobs.end());
//     std::sort(W.begin(), W.end());
//     int i = 0, r = 0, maxprft = 0;
//     for (int lv : W) {
//       // find maxprofix with lv
//       while (i < jobs.size() && jobs[i].first <= lv) {
//         maxprft = std::max(maxprft, jobs[i++].second);
//       }
//       r += maxprft;
//     }
//     return r;
//   }
// };

// D: 35 47 52 68 86
// P: 17 81  1 67  3
// W: 10 82 84 85 92

// 88ms 97.91% 21.8MB 13.13%
// dynamic programming
// O(N) O(N)
class Solution {
 public:
  int maxProfitAssignment(std::vector<int>& D,
                          std::vector<int>& P,
                          std::vector<int>& W) {
    int maxdiff = *std::max_element(D.begin(), D.end());
    // C[i] : max profit of difficulty i
    std::vector<int> C(maxdiff + 1, 0);
    for (int i = 0; i < D.size(); ++i)
      C[D[i]] = std::max(P[i], C[D[i]]);
    for (int i = 1; i <= maxdiff; ++i)
      C[i] = std::max(C[i], C[i-1]);
    int r = 0;
    for (int lv : W)
      r += lv >= maxdiff ? C[maxdiff] : C[lv];

    return r;
  }
};

int main() {
  // std::vector<int> D = {2,4,6,8,10};
  // std::vector<int> P = {10,20,30,40,50};
  // std::vector<int> W = {4,5,6,7};
  // std::vector<int> D = {13, 37, 58};
  // std::vector<int> P = {4, 90, 96};
  // std::vector<int> W = {34, 73, 45};
  std::vector<int> D = {68,35,52,47,86};
  std::vector<int> P = {67,17,1,81,3};
  std::vector<int> W = {92,10,85,84,82};
  Solution sln;
  printf("%d\n", sln.maxProfitAssignment(D, P, W));
  
  return 0;
}
