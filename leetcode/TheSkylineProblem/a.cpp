#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

// 36ms 79.48% 14.5MB 66.29%
// Q. what is the range of B.size()? [0..10000]
// Q. B is sorted already? yes
// Q. output should be sorted? yes
// Q. what is the range of B[i][0], B[i][1], b[i][2]? int
// Q. output should be merged by height? yes
// line sweeping
// O(NlgN) O(N)
class Solution {
 public:
  std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& B) {
    std::vector<std::pair<int, int>> E;  // edges;
    int l, r, h;  // left, right, height
    for (int i = 0; i < B.size(); ++i) {
      int l = B[i][0];
      int r = B[i][1];
      int h = B[i][2];
      E.push_back({l, -h});
      E.push_back({r,  h});
    }
    std::sort(E.begin(), E.end());
    std::vector<std::pair<int, int>> rslt;
    // max height
    std::multiset<int> msst;
    msst.insert(0);
    int pre = 0, cur = 0;
    for (int i = 0; i < E.size(); ++i) {
      auto e = E[i];
      if (e.second < 0)
        msst.insert(-e.second);
      else
        msst.erase(msst.find(e.second));
      cur = *(msst.rbegin());
      if (cur != pre) {
        rslt.push_back({e.first, cur});
        pre = cur;
      }
    }
    return rslt;
  }
};

// Inf loop
// class Solution {
//  public:
//   std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& B) {
//     std::vector<std::pair<int, int>> rslt;
//     // height, right
//     std::priority_queue<std::pair<int, int>> pq;
//     pq.push({0, -1});
//     B.push_back({-1, 0, 0});
//     for (auto& b : B) {
//       for (int t; (t = pq.top().second) < b[0];) {
//         while (pq.top().second <= t)
//           pq.pop();
//         if (rslt.back().second > pq.top().first) {
//           rslt.push_back({t, pq.top().first});
//         }
//       }
//       if (!rslt.empty() && rslt.back().first == b[0]) {
//         rslt.back().second = std::max(rslt.back().second, b[2]);
//       } else if (pq.top().first < b[2]) {
//         rslt.push_back({b[0], b[2]});
//       }
//       pq.push({b[2], b[1]});
//     }
//     return rslt;
//   }
// };

int main() {
  std::vector<std::vector<int>> B = {
    {2, 9, 10},
    {3, 7, 15},
    {5, 12, 12},
    {15, 20, 10},
    {19, 24, 8}    
  };
  Solution sln;
  auto r = sln.getSkyline(B);
  for (auto& a : r)
    printf("(%d, %d) ", a.first, a.second);
  printf("\n");
  return 0;
}
