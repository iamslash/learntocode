/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// A = [[0,2],[5,10],[13,23],[24,25]]
//                        i
// B = [[1,5],[8,12],[15,24],[25,26]]
//                j
// r =  [1,2] [5,5] [8,10] 

// // 76ms 7.74% 15.8MB 53.65%
// // O(max(A,B)) O(max(A,B))
// class Solution {
//  public:
//   std::vector<std::vector<int>> intervalIntersection(
//       std::vector<std::vector<int>>& A,
//       std::vector<std::vector<int>>& B) {
//     std::vector<std::vector<int>> ans;
//     int i = 0, j = 0;
//     while (i < A.size() && j < B.size()) {
//       auto &a = A[i], &b = B[j];
//       if (a[1] < b[0]) {
//         ++i;
//       } else if (a[0] > b[1]) {
//         ++j;
//       } else {
//         int maxx = std::max(a[0], b[0]);
//         int miny = std::min(a[1], b[1]);
//         ans.push_back({maxx, miny});
//         if (a[1] <= b[1])
//           ++i;
//         else
//           ++j;
//       }
//     }
//     return ans;        
//   }
// };

// 76ms 7.74% 15.7MB 78.13%
// O(max(A,B)) O(max(A,B))
class Solution {
 public:
  std::vector<std::vector<int>> intervalIntersection(
      std::vector<std::vector<int>>& A,
      std::vector<std::vector<int>>& B) {
    auto ita = A.begin();
    auto itb = B.begin();
    std::vector<std::vector<int>> ans;
    while (ita != A.end() && itb != B.end()) {
      int x = std::max((*ita)[0], (*itb)[0]);
      int y = std::min((*ita)[1], (*itb)[1]);
      if (x <= y)
        ans.push_back({x, y});
      if ((*ita)[1] < (*itb)[1])
        ++ita;
      else
        ++itb;
    }    
    return ans;
  }  
};

int main() {

  std::vector<std::vector<int>> A = {{0,2},{5,10},{13,23},{24,25}};
  std::vector<std::vector<int>> B = {{1,5},{8,12},{15,24},{25,26}};
  
  Solution sln;
  auto r = sln.intervalIntersection(A, B);
  for (auto& pt : r) {
    printf("(%d, %d) ", pt[0], pt[1]);
  }
  printf("\n");
  
  return 0;
}
