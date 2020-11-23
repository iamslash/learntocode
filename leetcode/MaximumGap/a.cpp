/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

// // 12ms 93.58% 9.4MB 64.94%
// // O(NlgN) O(N)
// class Solution {
//  public:
//   int maximumGap(std::vector<int>& V) {
//     if (V.size() <= 1)
//       return 0;
//     std::sort(V.begin(), V.end());
//     if (V[0] == V[V.size()-1])
//       return 0;
//     std::vector<int> D(V.size(), 0);
//     std::adjacent_difference(V.begin(), V.end(), D.begin());
//     return *std::max_element(D.begin()+1, D.end());
//   }
// };

// 12ms 81.49% 10MB 24.68%
// O(N) O(N)
class Solution {
 private:
  void count_sort(std::vector<int>& V, int exp) {
    int n = V.size();
    std::vector<int> cnts(10, 0);
    std::vector<int> rslt(n, 0);
    for (int i = 0; i < n; ++i)
      cnts[(V[i]/exp)%10]++;
    for (int i = 1; i < 10; ++i)
      cnts[i] += cnts[i-1];
    for (int i = n-1; i >= 0; --i) {
      int j = (V[i]/exp)%10;
      rslt[cnts[j]-1] = V[i];
      cnts[j]--;
    }
    for (int i = 0; i < n; ++i)
      V[i] = rslt[i];
  }

  void radix_sort(std::vector<int>& V) {
    int maxv = *std::max_element(V.begin(), V.end());
    for (int exp = 1; maxv / exp > 0; exp *= 10) {
      count_sort(V, exp);
    }
  }
 public:
  int maximumGap(std::vector<int>& V) {
    int n = V.size();
    if (n < 2)
      return 0;
    radix_sort(V);
    std::vector<int> D(n, 0);
    std::adjacent_difference(V.begin(), V.end(), D.begin());
    return *std::max_element(D.begin()+1, D.end());
  }
};

int main() {
  // std::vector<int> V = {3, 6, 9, 1};
  // std::vector<int> V = {1, 1, 1, 1};
  // 2901
  std::vector<int> V = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
  Solution sln;
  printf("%d\n", sln.maximumGap(V));
  return 0;
}
