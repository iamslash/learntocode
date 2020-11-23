/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <cstdint>
#include <vector>
#include <numeric>

// // Time Limit Exceed
// class Solution {
//  public:
//   std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& V, int g) {
//     int n = V.size();
//     int maxi = 0, maxj = g, maxk = 2 * g;
//     std::vector<int> psum(n, 0);
//     std::partial_sum(V.begin(), V.end(), psum.begin());
//     int sumi = psum[maxi+g-1]-psum[maxi+g-2];
//     int sumj = psum[maxj+g-1]-psum[maxj+g-2];
//     int sumk = psum[maxk+g-1]-psum[maxk+g-2];
//     int sum = sumi + sumj + sumk;

//     // printf("%d %d %d\n", maxi, maxj, maxk);

//     for (int i = 0; i <= n-g-g-g; ++i) {
//       sumi = psum[i+g-1]-psum[i+g-2];
//       for (int j = i+g; j <= n-g-g; ++j) {
//         sumj = psum[j+g-1]-psum[j+g-2];
//         for (int k = j+g; k <= n-g; ++k) {
//           sumk = psum[k+g-1]-psum[k+g-2];
//           int tum = sumi + sumj + sumk;
//           if (sum < tum) {
//             maxi = i;
//             maxj = j;
//             maxk = k;
//             sum = tum;
//           }          
//         }
//       }
//     }
//     return {maxi, maxj, maxk};
//   }
// };

//  n: 10
//                    i
//  F: 4  5 10 10 11 17 17 17 17 17
//     0  1  2  2  4  5  5  5  5  5
//  B:17 17 17 17 17 17 11 11  3  3                      
//     5  5  5  5  5  5  8  8  9  9
//  P: 4  9 19 25 36 53 57 68 69 72
//  V: 4  5 10  6 11 17  4 11  1  3
//
// 32ms 94.37% 13.8MB 23.19%
// O(N) O(N)
class Solution {
 public:
  std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& V, int k) {
    int n = V.size();
    std::vector<int64_t> ps(n, 0);
    std::partial_sum(V.begin(), V.end(), ps.begin());

    // forward[i]: {V[i] + ... + V[i+k-1], i}
    std::vector<std::pair<int, int>> forward(n);
    forward[0] = {ps[k-1], 0};
    for (int i = 1; i <= n - k; ++i) {
      int tum = ps[i+k-1] - ps[i-1];
      forward[i] = (forward[i-1].first >= tum) ?
          forward[i-1] : std::make_pair(tum, i); 
    }

    // backward[i]: {V[i] + ... + V[i+k-1], i}
    std::vector<std::pair<int, int>> backward(n+1);
    for (int i = n - k ; i >= 0; --i) {
      int tum = ps[i+k-1] - (i > 0 ? ps[i-1] : 0);
      backward[i] = (backward[i+1].first > tum) ?
          backward[i+1] : std::make_pair(tum, i);
    }

    int sum = 0;
    int maxi, maxj, maxk;
    // traverse middle
    for (int i = k; i <= n-k-k; ++i) {
      int tum = forward[i-k].first + ps[i+k-1]-ps[i-1] + backward[i+k].first;
      if (sum < tum) {
        sum = tum;
        maxi = forward[i-k].second;
        maxj = i;
        maxk = backward[i+k].second;
      }
    }
    return {maxi, maxj, maxk};    
  }
};

int main() {

  std::vector<int> V = {4,5,10,6,11,17,4,11,1,3};
  int k = 1;

  Solution sln;
  auto rslt = sln.maxSumOfThreeSubarrays(V, k);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
