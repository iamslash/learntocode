/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <set>

// 2 7 11 15
// 1 4 10 11

// 8 12 24 32
// 11 13 25 32

// // 176ms 69.485 21.6MB 33.34%
// // O(NlgN) O(N)
// class Solution {
//  public:
//   std::vector<int> advantageCount(std::vector<int>& A,
//                                   std::vector<int>& B) {
//     std::multiset<int> sst(A.begin(), A.end());
//     for (int i = 0; i < A.size(); ++i) {
//       auto it = *sst.rbegin() <= B[i] ?
//           sst.begin() :
//           sst.upper_bound(B[i]);
//       A[i] = *it;
//       sst.erase(it);
//     }
//     return A;
//   }
// };

// 152ms 94.14% 16.4MB 73.48
class Solution {
 public:
  std::vector<int> advantageCount(std::vector<int>& A,
                                  std::vector<int>& B) {
    int n = A.size();
    std::sort(A.begin(), A.end());
    std::vector<int> rslt(n);
    std::vector<std::pair<int, int>> b2i;
    for (int i = 0; i < n; ++i)
      b2i.push_back({B[i], i});
    std::sort(b2i.begin(), b2i.end());
    int i = n - 1, j = 0, k = n - 1;
    while (i >= 0) {
      if (b2i[i].first < A[k]) {
        rslt[b2i[i].second] = A[k];
        --k;
      } else {
        rslt[b2i[i].second] = A[j];
        ++j;
      }
      --i;
    }
    return rslt;
  }
};

int main() {

  std::vector<int> A = {2, 7, 11, 15};
  std::vector<int> B = {1, 10, 4, 11};
  
  Solution sln;

  auto r = sln.advantageCount(A, B);
  for (int a : r)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
