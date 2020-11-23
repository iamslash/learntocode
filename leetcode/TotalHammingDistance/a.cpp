/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // O(N) O(1)
// // 68ms 50.00%
// class Solution {
//  public:
//   int totalHammingDistance(std::vector<int>& V) {
//     int n = V.size();
//     if (n < 2)
//       return 0;
//     int rslt = 0;
//     int pq[2];
//     while (true) {
//       int zero_cnt = 0;
//       pq[0] = 0;  // counts whose lsb is 0
//       pq[1] = 0;  // counts whose lsb is 1
//       for (int i = 0; i < n; ++i) {
//         if (V[i] == 0)
//           zero_cnt++;
//         pq[V[i] % 2]++;
//         V[i] >>= 1;
//       }
//       rslt += pq[0] * pq[1];
//       if (zero_cnt == n)
//         break;
//     }
//     return rslt;
//   }
// };

// O(N) O(1)
// 52ms 100.00%
class Solution {
 public:
  int totalHammingDistance(std::vector<int> V) {
    int rslt = 0;
    int n = V.size();
    for (int i = 0; i < 32; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if ((V[j] >> i) & 0x01)
          cnt += 1;
      }
      rslt += cnt * (n - cnt);
    }
    return rslt;
  }
};

int main() {
  // std::vector<int> V = {4, 14, 2};
  std::vector<int> V = {1337, 7331};
  Solution sln;
  printf("%d\n", sln.totalHammingDistance(V));
  
  return 0;
}
