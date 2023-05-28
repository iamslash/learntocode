// Copyright (C) 2023 by iamslash

import java.util.*;

// [98,54,6,34,66,63,52,39]
// 62

// // 3ms 33.33% 43.4MB 33.33%
// // sort
// // O(NlgN) O(1)
// class Solution {
//     public int buyChoco(int[] prices, int money) {
//         Arrays.sort(prices);
//         int sum = prices[0] + prices[1];
//         if (sum > money) {
//             return money;
//         }
//         return money - sum;
//     }
// }

// 2ms 100.00% 43.7MB 33.33%
// math
// O(N) O(1)
class Solution {
    public int buyChoco(int[] prices, int money) {
        int small1st = Integer.MAX_VALUE, small2nd = Integer.MAX_VALUE;
        for (int price : prices) {
            if (price < small1st) {
                small2nd = small1st;
                small1st = price;
            } else if (price < small2nd) {
                small2nd = price;
            }
        }
        int sum = small1st + small2nd;
        if (sum <= money) {
            return money - sum;
        }
        return money; 
    }
}
