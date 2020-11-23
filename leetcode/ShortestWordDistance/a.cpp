/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdlib>

// // 20ms 61.93% 11.7MB 90.91%
// // O(N^2) O(1)
// class Solution {
//  public:
//   int shortestDistance(std::vector<std::string>& W,
//                        std::string a, std::string b) {
//     int rslt = INT_MAX;
//     for (auto it_a = W.begin(); it_a != W.end(); ++it_a) {
//       if (*it_a != a)
//         continue;
//       auto it_b = std::find(it_a, W.end(), b);
//       int dab = it_b == W.end() ? INT_MAX : it_b - it_a;
//       rslt = std::min(rslt, dab);
//     }
//     for (auto it_b = W.begin(); it_b != W.end(); ++it_b) {
//       if (*it_b != b)
//         continue;
//       auto it_a = std::find(it_b, W.end(), a);
//       int dba = it_a == W.end() ? INT_MAX : it_a - it_b;
//       rslt = std::min(rslt, dba);
//     }

//     return rslt;
//   }
// };

// 16ms 100.00% 11.6MB 90.91%
// O(N) O(1)
class Solution {
 public:
  int shortestDistance(std::vector<std::string>& W,
                       std::string a, std::string b) {
    
    int posa = -1;
    int posb = -1;
    int rslt = INT_MAX;
    for (int i = 0; i < W.size(); ++i) {
      if (W[i] == a) {
        if (posa < posb)
          rslt = std::min(rslt, i - posb);
        posa = i;
      }
      if (W[i] == b) {
        if (posb < posa)
          rslt = std::min(rslt, i - posa);
        posb = i;
      }
    }
    return rslt;
  }
};

int main() {

  
  
  return 0;
}
