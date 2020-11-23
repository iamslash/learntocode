/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// // 16ms 80.97% 12.5MB 10.16%
// // O(N) O(N)
// class Solution {
//  public:
//   std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& I,
//                                        std::vector<int>& J) {
//     std::vector<std::vector<int>> r;
//     int i = 0, n = I.size();
//     while (i < n && I[i][1] < J[0])
//       r.push_back(I[i++]);
//     while (i < n && J[1] >= I[i][0]) {
//       J[0] = std::min(J[0], I[i][0]);
//       J[1]   = std::max(J[1], I[i][1]);
//       ++i;
//     }
//     r.push_back(J);
//     while (i < n)
//       r.push_back(I[i++]);
//     return r;    
//   }
// };

// 16ms 80.97% 12.6MB 7.08%
// O(N) O(1)
class Solution {
 public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& I,
                                       std::vector<int>& J) {
    auto cmp = [](const std::vector<int>& a,
                  const std::vector<int>& b) {
                 return a[1] < b[0];
               };
    auto pr = std::equal_range(I.begin(), I.end(), J, cmp);
    auto i = pr.first;
    auto j = pr.second;
    if (i == j) {
      I.insert(i, J);
    } else {
      j = std::prev(j);
      (*j)[0] = std::min(J[0], (*i)[0]);
      (*j)[1] = std::max(J[1], (*j)[1]);
      I.erase(i, j);
    }
    return I;
  }
};

int main() {
                    
  std::vector<std::vector<int>> I = {{1, 3}, {6, 9}};
  std::vector<int> J = {2, 5};
  Solution sln;
  auto rslt = sln.insert(I, J);
  for (const auto& a : rslt)
    printf("(%d, %d) ", a[0], a[1]);
  printf("\n");
  
  return 0;
}
