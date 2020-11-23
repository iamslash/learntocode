/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

// // 256ms 27.27%
// // partialsum
// // O(N^2) O(1)
// class Solution {
//  public:
//   int subarraySum(std::vector<int>& N, int K) {
//     int cnt = 0;
//     for (int i = 1; i < N.size(); ++i)
//       N[i] += N[i-1];
//     for (int i = 0; i < N.size(); ++i) {
//       if (N[i] == K)
//         ++cnt;
//       for (int j = i+1; j < N.size(); ++j) {
//         if (N[j] - N[i] == K)
//           ++cnt;
//       }
//     }
//     return cnt;
//   }
// };

// K : 2
// N : 1 1 1
// s :
// c :
// m : 

// 20ms 99.59%
// hash
// O(N) O(N)
class Solution {
 public:
  int subarraySum(std::vector<int>& N, int K) {
    int cnt = 0;
    int sum = 0;
    std::unordered_map<int, int> ump;
    ump[0] = 1;
    for (int i = 0; i < N.size(); ++i) {
      sum += N[i];
      cnt += ump.count(sum-K) > 0 ? ump[sum-K] : 0;
      ump[sum]++;
    }
    return cnt;
  }
};


int main() {
  
  std::vector<int> N = {1, 1, 1};
  int K = 2;
  Solution sln;
  printf("%d\n", sln.subarraySum(N, K));
  
  return 0;
}
