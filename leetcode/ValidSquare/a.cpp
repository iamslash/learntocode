/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>

// 0ms 100.00%
// O(1) O(N)
class Solution {
 private:
  int d(std::vector<int>& a, std::vector<int>& b) {
    return (a[0] - b[0]) * (a[0] - b[0]) +
        (a[1] - b[1]) * (a[1] - b[1]);
  }
 public:
  bool validSquare(
      std::vector<int>& p1, std::vector<int>& p2,
      std::vector<int>& p3, std::vector<int>& p4) {
    std::unordered_set<int> ust = {
      d(p1, p2),
      d(p1, p3),
      d(p1, p4),
      d(p2, p3),
      d(p2, p4),
      d(p3, p4),
    };
    return ust.count(0) == 0 && ust.size() == 2;
    
  }
};

void printb(bool b) {
  printf("%s\n", b ? "True" : "False");
}

int main() {

  // std::vector<std::vector<int>> V = {
  //   {0, 0},    
  //   {1, 1},    
  //   {1, 0},    
  //   {0, 1},
  // };
  std::vector<std::vector<int>> V = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}};
  Solution sln;
  printb(sln.validSquare(V[0], V[1], V[2], V[3]));

  return 0;
}
