/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// // 48ms 43.07% 11.6MB 22.86%
// // cartesian product
// // O(N^2) O(N)
// class Solution {
//  private:
//   bool isValid(int a, int b) {
//     return !((b <= 0.5 * a + 7) ||
//              (b > a) ||
//              (b > 100 && a < 100));
//   }
//  public:
//   int numFriendRequests(std::vector<int>& A) {
//     std::unordered_map<int, int> cnts;
//     for (int a : A)
//       cnts[a]++;
//     int rslt = 0;
//     for (auto& pra : cnts) {
//       for (auto& prb : cnts) {
//         if (isValid(pra.first, prb.first)) {
//           rslt += pra.second *
//               (prb.second - (pra.first == prb.first ? 1 : 0));
//         }
//       }
//     }
//     return rslt;
//   }
// };

// 40ms 76.85% 11.3MB 48.57%
class Solution {
 public:
  int numFriendRequests(std::vector<int>& A) {
    std::vector<int> a2c(121, 0);
    int rslt = 0;
    for (int a : A)
      a2c[a]++;
    for (int a = 15; a <= 120; ++a) {
      for (int b = 0.5 * a + 8; b <= a; ++b) {
        rslt += a2c[b] * (a2c[a] - (a == b));
      }
    }
    return rslt;
  }
};

int main() {
  return 0;
}
