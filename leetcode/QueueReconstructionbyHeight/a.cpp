/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

// 7,0 5,0 
// 44ms 21.78%
class Solution {
 public:
  std::vector<std::pair<int, int>> reconstructQueue(
      std::vector<std::pair<int, int>>& P) {
    std::vector<std::pair<int, int>> r;
    std::sort(P.begin(), P.end(),
              [](const std::pair<int, int> a,
                 const std::pair<int, int> b) {
                return a.first == b.first ?
                    a.second < b.second :
                               a.first > b.first;
              });
    for (auto pr : P)
      r.insert(r.begin() + pr.second , pr);
    return r;
  }
};

int main() {
  std::vector<std::pair<int,int>> P = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};

  Solution sln;
  auto rslt = sln.reconstructQueue(P);
  for (const auto& pr : rslt)
    printf("[%d,%d] ", pr.first, pr.second);
  printf("\n");
  
  return 0;
}
