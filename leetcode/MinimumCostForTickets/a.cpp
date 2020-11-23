/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

//    0 1 4 6 7 8 20
// 2  0 2
// 7  0       7
// 15 0           15

// // 4ms 80.70% 9.3MB 16.77%
// // dynamic programming
// // O(N) O(N)
// class Solution {
//  public:
//   int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
//     std::unordered_set<int> dayust(days.begin(), days.end());
//     std::vector<int> C(366);
//     for (int i = 1; i < 366; ++i) {
//       if (dayust.find(i) == dayust.end())
//         C[i] = C[i-1];
//       else
//         C[i] = std::min(
//             {
//               C[i-1]+costs[0],
//               C[std::max(0, i-7)]+costs[1],
//               C[std::max(0, i-30)]+costs[2]
//             }
//                );
//     }
//     return C[365];
//   }
// };

// 4ms 80.70% 9.1MB 31.36%
// dynamic programming
// O(N) O(N)
class Solution {
 public:
  int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
    std::unordered_set<int> dayust(days.begin(), days.end());
    std::vector<int> C(30);
    for (int day = days.front(); day <= days.back(); ++day) {
      if (dayust.find(day) == dayust.end()) {
        C[day % 30] = C[(day - 1) % 30];
      } else {
        C[day % 30] = std::min(
            {
              C[(day-1)%30] + costs[0],
                  C[std::max(0, (day-7)  %30)] + costs[1],
                  C[std::max(0, (day-30) %30)] + costs[2]
            });
      }
    }
    return C[days.back() % 30];
  }
};

int main() {
  return 0;
}
