/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
 public:
  std::vector<std::pair<int, int>> reconstructQueue(
      std::vector<std::pair<int, int>>& P) {
    std::sort(P.begin(), P.end(),
              [](const std::pair<int, int>& lhs,
                 const std::pair<int, int>& rhs) {
                return lhs.first > rhs.first ||
                    (lhs.first == rhs.first &&
                     lhs.second < rhs.second);
              });
    std::vector<std::pair<int, int>> rslt;
    for (const auto& p : P)
      rslt.insert(rslt.begin() + p.second, p);
    return rslt;
  }
};

// 7,0 7,1 6,1 5,0 5,2 4,4
// 5,0 7,0 5,2 6,1 4,4 7,1
int main() {
  std::vector<std::pair<int, int>> P = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
  Solution sln;
  auto rslt = sln.reconstructQueue(P);
  for (const auto& p : rslt)
    printf("%d, %d\n", p.first, p.second);  
  return 0;
}
