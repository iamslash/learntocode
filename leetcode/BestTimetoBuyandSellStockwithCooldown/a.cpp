/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>
// |-|                  |-|           
// ->s0 <--cooldown-- s2<-|
//   |                 ^
//   |                 |
//   buy ----> s1 ---sell
//            |^
//            -|
//          
//
//  P:  1 2 4
//
// s0:  0 0 0
// s1: -1-1-1
// s2:  - 1 3
//
// 4ms 99.62%

// buy[i] = max(rest[i - 1] - price, buy[i - 1]);
// sell[i] = max(buy[i - 1] + price, sell[i - 1])
// rest[i] = max(sell[i - 1], buy[i - 1], rest[i - 1])
// buy[i] = max( sell[i-2] - price, buy[i-1]); 
// sell[i] =  max(buy[i-1] + price, sell[i-1]) 

class Solution {
 public:
  int maxProfit(std::vector<int>& P) {
    int n = P.size();
    if (n == 0)
      return 0;
    std::vector<int> s0(n, 0);
    std::vector<int> s1(n, 0);
    std::vector<int> s2(n, 0);
    s1[0] = -P[0];
    s2[0] = std::numeric_limits<int>::min();
    
    for (int i = 1; i < n; ++i) {
      s0[i] = std::max(s0[i-1], s2[i-1]);
      s1[i] = std::max(s1[i-1], s0[i-1] - P[i]);
      s2[i] = s1[i-1] + P[i];
    }
    
    return std::max(s0[n-1], s2[n-1]);
  }
};

int main() {
  // std::vector<int> P = {1, 2, 3, 0, 2};
  std::vector<int> P = {1, 2, 4};

  Solution sln;
  printf("%d\n", sln.maxProfit(P));
  
  return 0;
}
