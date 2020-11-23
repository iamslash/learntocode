/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

// i
// 1 2 2
//   j

//   i
// 1 1 2
//       j


// i
// 1 2 2 2 5
//     j

// // 224ms 72.67% 24.4MB 100.00%
// // hashmap
// // O(NlgN) O(N)
// class Solution {
//  public:
//   std::vector<int> rearrangeBarcodes(std::vector<int>& B) {
//     std::unordered_map<int, int> ump;  // {num: cnt}
//     std::set<std::pair<int, int>> sst;            // {cnt, num}
//     int pos = 0, n = B.size();
//     for (int num : B)
//       ump[num]++;
//     for (auto it = ump.begin(); it != ump.end(); ++it) {
//       sst.insert({it->second, it->first});
//     }
//     for (auto it = sst.rbegin(); it != sst.rend(); ++it) {
//       for (int cnt = 0; cnt < it->first; ++cnt, pos += 2) {
//         if (pos >= n)
//           pos = 1;
//         B[pos] = it->second;
//       }
//     }
//     return B;
//   }
// };

// 180ms 99.33% 18.1MB 100.00%
// vector
// O(N) O(1)
class Solution {
 public:
  std::vector<int> rearrangeBarcodes(std::vector<int>& B) {
    std::vector<int> cnts(10001);
    // max count of num, num of max count, position to insert
    int maxcnt = 0, maxnum = 0, pos = 0, n = B.size();
    for (int num : B) {
      maxcnt = std::max(maxcnt, ++cnts[num]);
      if (maxcnt == cnts[num])
        maxnum = num;
    }
    for (int i = 0; i <= 10000; ++i) {
      int num = i == 0 ? maxnum : i;
      while (cnts[num]-- > 0) {
        B[pos] = num;
        pos += 2;
        if (pos >= n)
          pos = 1;
      }
    }
    return B;
  }
};

int main() {
  std::vector<int> B = {1, 1, 1, 2, 2, 2};

  Solution sln;
  auto r = sln.rearrangeBarcodes(B);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
