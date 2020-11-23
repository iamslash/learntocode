/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 8ms 100.00% 9.7MB 100.00%
// DFA
// O(N) O(1)
class Solution {
 public:
  int maxProfit(std::vector<int>& P) {
    int b1 = std::numeric_limits<int>::min();
    int b2 = std::numeric_limits<int>::min();
    int s1 = 0, s2 = 0;
    for (int p : P) {
      b1 = std::max(b1, -p);   // hold or buy1
      s1 = std::max(s1, b1+p); // hold or sell1
      b2 = std::max(b2, s1-p); // hold or buy2
      s2 = std::max(s2, b2+p); // hold or sell2
    }
    return s2;
  }
};

int main() {

  // std::vector<int> P = {3,3,5,0,0,3,1,4};
  // std::vector<int> P = {1,2,3,4,5};
  std::vector<int> P = {7,6,4,3,1};

  Solution sln;
  printf("%d\n", sln.maxProfit(P));
  
  return 0;
}
