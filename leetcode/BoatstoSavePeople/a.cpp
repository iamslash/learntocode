/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>

// // 204ms 5.59% 20MB 5.19%
// // O(NlgN) O(N) 
// class Solution {
//  public:
//   int numRescueBoats(std::vector<int>& people, int limit) {
//     int rslt = 0;
//     std::map<int, int> smp;
//     for (int p : people)
//       smp[-p]++;
//     for (int p : people) {
//       // printf("%d \n", p);
//       if (!smp.count(-p))
//         continue;
//       if (--smp[-p] <= 0)
//         smp.erase(-p);
      
//       int d = limit - p;
//       if (d > 0 && smp.size()) {
//         auto it = smp.lower_bound(-d);
//         if (it != smp.end() && --it->second <= 0)
//             smp.erase(it);
//       }
//       ++rslt;
//       // for (auto pr : smp)
//       //   printf("  %d:%d ", pr.first, pr.second);
//       // printf("\n");
//     }
//     return rslt;
//   }
// };

// 116ms 73.63% 13.8MB 60.38
// two pointers
// O(NlgN) O(1)
class Solution {
 public:
  int numRescueBoats(std::vector<int>& P, int limit) {
    std::sort(P.begin(), P.end());
    int l = 0, r = P.size() - 1, rslt = 0;
    while (l < r) {
      if (P[l] + P[r] <= limit)
        ++l, --r;
      else
        --r;
      ++rslt;
    }
    if (l == r)
      rslt++;
    return rslt;
  }
};

int main() {

  // std::vector<int> people = {1, 2};
  // int limit = 3;
  // std::vector<int> people = {3, 2, 2, 1};
  // int limit = 3;
  // std::vector<int> people = {3, 5, 3, 4};
  // int limit = 5;
  std::vector<int> people = {3, 1, 7};
  int limit = 7;

  Solution sln;
  printf("%d\n", sln.numRescueBoats(people, limit));
  
  return 0;
}
