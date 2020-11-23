/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// 1 2 3
//   2 3 4
//        6 7 8

// 1 2 3 4 6 7 8
// 1 2 3 1 1 1 1

// // 256ms 6.49% 10.4MB 91.87%
// // O(HW) O(H)
// class Solution {
//  public:
//   bool isNStraightHand(std::vector<int>& H, int W) {
//     int n = H.size();
//     std::sort(H.begin(), H.end());
//     std::vector<std::pair<int, int>> G(n / W);  // {last number, count}
//     for (int num : H) {
//       for (int j = 0; j <= G.size(); ++j) {
//         if (j == G.size())
//           return false;
//         if (G[j].second == 0 ||
//             (G[j].second < W && G[j].first == num - 1)) {
//           G[j].first = num;
//           G[j].second++;
//           break;
//         }
//       }
//     }
//     return true;
//   }
// };

// map
// 40ms 99.76% 10.1MB 94.74%
// O(H) O(W)
class Solution {
 public:
  bool isNStraightHand(std::vector<int>& H, int W) {
    std::vector<int> cnts(W);
    for (int i : H)
      cnts[i%W]++;
    int grp = H.size() / W;
    for (int i : cnts) {
      if (i != grp)
        return false;
    }
    return true;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  std::vector<int> H = {1,2,3,6,2,3,4,7,8};
  int W = 3;
  Solution sln;
  printb(sln.isNStraightHand(H, W));
  
  return 0;
}
