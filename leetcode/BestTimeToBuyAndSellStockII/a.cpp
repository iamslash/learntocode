/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

// 0 1 2 3 4 5 6
// 

class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int r = 0;
    if (prices.size() <= 1)
      return r;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i-1])
        r += prices[i] - prices[i-1];
    }

    return r;
  }
};

int main() {
  Solution s;
  std::vector<int> v = {1,2,1};
  printf("%d\n", s.maxProfit(v));
  // printf("%d\n", INT_MIN);
  return 0;
}
