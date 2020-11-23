/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// K: 5
// A: 4 5 0 -2 -3 1
//    i

// // Time Limit Exceeded
// // brute force
// // O(N^2) O(N)
// class Solution {
//  public:
//   int subarraysDivByK(std::vector<int>& A, int K) {
//     std::vector<int> sumofsub;
//     int ans = 0;
//     for (int a : A) {
//       std::vector<int> tmp;
//       for (int num : sumofsub) {
//         tmp.push_back((num + a) % K);
//         if (tmp.back() == 0)
//           ans++;
//       }
//       tmp.push_back(a % K);
//       if (tmp.back() == 0)
//         ans++;
//       sumofsub = tmp;
//     }
//     return ans;
//   }
// };

// 52ms 96.31% 12.2MB 70.88%
// prefix sum
// O(N) O(N)
class Solution {
 public:
  int subarraysDivByK(std::vector<int>& A, int K) {
    std::vector<int> cnt(K);
    cnt[0] = 1;
    int prf = 0, ans = 0;
    for (int a : A) {
      // prf should not be negative
      prf = (prf + a % K + K) % K;
      ans += cnt[prf]++;
    }
    return ans;
  }
};

int main() {

  int K = 5;
  std::vector<int> V = {4, 5, 0, -2, -3, 1};
  
  Solution sln;
  printf("%d\n", sln.subarraysDivByK(V, K));
  
  return 0;
}
