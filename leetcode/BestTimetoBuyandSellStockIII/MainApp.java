// Copyright (C) 2024 by iamslash

import java.util.*;

// 4ms 70.02% 61MB 50.09%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int maxProfit(int[] prices) {
      int maxProfitAfterBuy1 = Integer.MIN_VALUE, maxProfitAfterSell1 = 0;
      int maxProfitAfterBuy2 = Integer.MIN_VALUE, maxProfitAfterSell2 = 0;
      for (int price : prices) {
          maxProfitAfterBuy1 = Math.max(maxProfitAfterBuy1, -price);
          maxProfitAfterSell1 = Math.max(maxProfitAfterSell1, maxProfitAfterBuy1 + price);
          maxProfitAfterBuy2 = Math.max(maxProfitAfterBuy2, maxProfitAfterSell1 -price);
          maxProfitAfterSell2 = Math.max(maxProfitAfterSell2, maxProfitAfterBuy2 + price);                                    
      }
      return maxProfitAfterSell2;
    }
}
