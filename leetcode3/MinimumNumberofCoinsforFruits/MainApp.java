// Copyright (C) 2023 by iamslash

import java.util.*;

//             i
// prices: 3 1 2
//    ans: 3 1

//         i
// prices: 1 10  1  1
//    ans: 1

// Idea: recursive dynamic programming
//
// dfs(i)
//   Return: min coins for from purchasing prices[i]
//        i: fruit index to be purchased
//
// Ex)
// dfs(1)
//   Can skip 2 items.
//   Return: min coins for purchasing prices[1]
//   All cases:
//     Purchase from prices[2]: 0 skip
//     Purchase from prices[3]: 1 skip
//     Purchase from prices[4]: 2 skip
//
//                         dfs(0)
//              /                          \
//         dfs(1)                         dfs(2)
//     /     |     \               /     /      \     \
// dfs(2)  dfs(3)  dfs(4)     dfs(3)  dfs(4)  dfs(5)  dfs(6)

// 19ms 100.00% 43.5MB 100.00%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
    private int dfs(int[] prices, int[] C, int i) {
        // base
        if (i >= prices.length) {
            return 0;
        }
        // memo
        if (C[i] > 0) {
            return C[i];
        }
        // recursion
        int rst = Integer.MAX_VALUE;
        // prices[] is a 1-based indexed array.
        // i + 1 + i + 1 = 2 * i + 2
        for (int j = i + 1; j <= 2 * i + 2; ++j) {
            rst = Math.min(rst, dfs(prices, C, j));
        }
        return C[i] = rst + prices[i];
    }
    public int minimumCoins(int[] prices) {
        int[] C = new int[1001];
        return dfs(prices, C, 0);
    }
}
