/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 8ms 100.00% 8.9MB 79.44%
// O(NK) O(K)
class Solution {
 public:
  int maxProfit(int k, std::vector<int>& P) {
    if (k <= 0 || P.size() < 2)
      return 0;
    if (k > P.size()/2) {
      int buy = -P[0], sell = 0;
      for (int i = 1; i < P.size(); ++i) {
        buy = std::max(buy, sell - P[i]);
        sell = std::max(sell, buy + P[i]);
        // printf("%d %d\n", buy, sell);
      }
      return std::max(sell, 0);
    }
    std::vector<int> buy(k, INT_MIN);
    std::vector<int> sell(k, 0);
    buy[0] = -P[0];
    for (int i = 1; i < P.size(); ++i) {
      buy[0] = std::max(buy[0], -P[i]);
      sell[0] = std::max(sell[0], buy[0] + P[i]);
      for (int j = 1; j < k; ++j) {
        buy[j] = std::max(buy[j], sell[j-1] - P[i]);
        sell[j] = std::max(sell[j], buy[j] + P[i]);
      }
    }
    return std::max(sell[k-1], 0);
  }
};

int main() {

  // std::vector<int> P = {2, 4, 1};
  // int k = 2;
  // std::vector<int> P = {3, 2, 6, 5, 0, 3};
  // int k = 7;
  std::vector<int> P = {1, 2};
  int k = 1;

  Solution sln;
  printf("%d\n", sln.maxProfit(k, P));
  
  return 0;
}
