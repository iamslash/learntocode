/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/gas-station/description/

#include <cstdio>
#include <vector>


// gas  : 1 2 3 4 5
// cost : 3 4 5 1 2
//       -2-2-2 3 3

// gas  : 5 1 2 3 4
// cost : 4 4 1 5 1
//        1-3 1-2 3

// gas  : 4 5 2 6 5 3
// cost : 3 2 7 3 2 9
//        1 3-5 3 3-6

// gas  : 4 5
// cost : -45
//        0 0
class Solution {
 public:
  int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    if (gas.empty() || cost.empty())
      return -1;
    int start = 0;
    int total = 0;
    int tank  = 0;
    int diff  = 0;
    for (int i = 0; i < gas.size(); ++i) {
      diff   = gas[i] - cost[i];
      tank  += diff;
      total += diff;
      printf("i: %d t: %d total: %d \n", i, tank, total);
      if (tank < 0) {
        start = i + 1;
        tank  = 0;
      }
    }
    return total >= 0 ? start : -1;
  }
};

int main() {
  // std::vector<int> G = {1, 2, 3, 4, 5};
  // std::vector<int> C = {3, 4, 5, 1, 2};
  // std::vector<int> G = {2, 3, 4};
  // std::vector<int> C = {3, 4, 3};
  // std::vector<int> G = {5, 1, 2, 3, 4};
  // std::vector<int> C = {4, 4, 1, 5, 1};
  std::vector<int> G = {4, 5, 2, 6, 5, 3};
  std::vector<int> C = {3, 2, 7, 3, 2, 9};
  Solution s;
  printf("%d\n", s.canCompleteCircuit(G, C));  
  return 0;
}
