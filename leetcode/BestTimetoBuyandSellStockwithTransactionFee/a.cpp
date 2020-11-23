/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 140ms 11.94% 15.4MB 39.08%
// O(N) O(1)
class Solution {
 public:
  int maxProfit(std::vector<int>& P, int fee) {
    int64_t buy = std::numeric_limits<int64_t>::min(); // last action buy
    int64_t sel = 0; // last action sell
    for (int price : P) {
      int64_t tmp = sel;
      sel = std::max(sel, buy + price);
      buy = std::max(buy, tmp - price - fee);
    }
    return sel;
  }
};

int main() {
  std::vector<int> P = {1, 3, 2, 8, 4, 9};
  int fee = 2;
  Solution sln;
  printf("%d\n", sln.maxProfit(P, fee));
  return 0;
}
