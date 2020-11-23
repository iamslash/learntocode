/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// 13
// 4 5 6
// 6 4 7
// 4 3 5
// 2 3 5

// // 12ms 62.12% 10.2MB 100.00%
// // map
// // O(NlgN) O(N)
// class Solution {
//  public:
//   bool carPooling(std::vector<std::vector<int>>& T, int cap) {
//     std::map<int, int> evts;
//     for (auto& v : T) {
//       evts[v[1]] -= v[0];
//       evts[v[2]] += v[0];
//     }
//     for (auto& evt : evts) {
//       cap += evt.second;
//       if (cap < 0)
//         return false;
//     }
//     return true;
//   }
// };

// 8ms 93.59% 10MB 100.00%
// vector
// O(N) O(N)
class Solution {
 public:
  bool carPooling(std::vector<std::vector<int>>& T, int cap) {
    std::vector<int> evts(1001);
    for (auto& v : T) {
      evts[v[1]] -= v[0];
      evts[v[2]] += v[0];
    }
    for (int i = 0; i < evts.size(); ++i) {
      cap += evts[i];
      if (cap < 0)
        return false;
    }
    return true;
  }
};

int main() {
  return 0;
}
