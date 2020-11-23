/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

// // 1340ms 7.17%
// // O(N^2) O(N)
// class Solution {
//  public:
//   int longestConsecutive(std::vector<int>& V) {
//     std::unordered_set<int> ust;
//     int rslt = 0;
//     for (int a : V) {
//       ust.insert(a);
//       int l = a, r = a + 1;
//       while (ust.count(l) > 0)
//         --l;
//       while (ust.count(r) > 0)
//         ++r;
//       rslt = std::max(rslt, r - l - 1);
//     }
//     return rslt;
//   }
// };

// 8ms 100.00% 9.2MB 93.85%
// O(NlgN) O(1)
class Solution {
 public:
  int longestConsecutive(std::vector<int>& V) {
    if (V.empty())
      return 0;
    int n = V.size();
    int rst = 0, cnt = 1;
    std::sort(V.begin(), V.end());
    for (int i = 1; i < n; ++i) {
      if (V[i] == V[i-1]) {
        continue;
      } else if (V[i] - V[i-1] == 1) {
        ++cnt;
      } else  {
        rst = std::max(rst, cnt);
        cnt = 1;
      }
    }
    rst = std::max(rst, cnt);
    return rst;
  }
};

int main() {

  std::vector<int> V = {100, 4, 200, 1, 3, 2};
  Solution sln;
  printf("%d\n", sln.longestConsecutive(V));
  
  return 0;
}
