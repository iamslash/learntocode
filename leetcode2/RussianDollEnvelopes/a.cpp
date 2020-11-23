/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

// E: [[5,4],[6,4],[6,7],[2,3]]
//                          i
// E: [[2,3],[5,4],[6,4],[6,7]]
//                    j
// C: 1 2 3 3

// // 652ms 30.39% 13.6MB 100.00%
// // dynamic programming
// // O(N^2) O(N)
// class Solution {
//  public:
//   int maxEnvelopes(std::vector<std::vector<int>>& E) {
//     if (E.empty())
//       return 0;
//     std::sort(E.begin(), E.end(), [](const std::vector<int>& a,
//                                      const std::vector<int>& b) {
//                                     if (a[0] == b[0])
//                                       return a[1] < b[1];
//                                     return a[0] < b[0];
//                                   });
//     std::vector<int> C(E.size(), 1);
//     for (int i = 0; i < E.size(); ++i) {
//       for (int j = 0; j < i; ++j) {
//         if (E[j][0] < E[i][0] && E[j][1] < E[i][1]) {
//           C[i] = std::max(C[i], C[j]+1);
//         }
//       }
//     }
//     return *max_element(C.begin(), C.end());
//   }
// };


// E: [[5,4],[6,4],[6,7],[2,3]]
//                          i                   
// E: [[2,3],[5,4],[6,7],[6,5]]
//                    
// L: 3 5 7

// sort, binary search
// O(NlgN) O(N)
class Solution {
 public:
  int maxEnvelopes(std::vector<std::vector<int>>& E) {
    if (E.size() <= 1) {
      return E.size();
    }
    std::sort(E.begin(), E.end(), [](const std::vector<int>& a,
                                     const std::vector<int>& b) {
                                    if (a[0] == b[0])
                                      return a[1] > b[1];
                                    return a[0] < b[0];
                                  });
    std::vector<int> lis;
    for (auto& e : E) {
      auto it = std::lower_bound(lis.begin(), lis.end(), e[1]);
      if (it == lis.end())
        lis.push_back(e[1]);
      else
        lis[it - lis.begin()] = e[1];
    }
    return lis.size();
  }
};

int main() {
  return 0;
}
