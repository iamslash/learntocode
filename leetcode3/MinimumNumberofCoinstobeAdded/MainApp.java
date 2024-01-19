// Copyright (C) 2024 by iamslash

import java.util.*;


// Idea: greedy
//
// Sort coins ascendingly.
// If we can make numbers in [1, maxReach],
// we can make numbers in [1, maxReach + maxReach]
// Check we can make the number of maxReach + 1.

//                i
//    coins: 1 4 10
// maxReach: 7
//     need: 2
//
//           i
//    coins: 4 10
// maxReach: 0
//     need: 0

// 23ms 83.50% 62.2MB 5.81%
// greedy
// O(NlgN) O(1)
class Solution {
    public int minimumAddedCoins(int[] coins, int target) {
        Arrays.sort(coins);
        int maxReach = 0, ans = 0;
        int idx = 0, n = coins.length;

        while (idx < n && maxReach < target) {
            if (coins[idx] <= maxReach + 1) {
                maxReach += coins[idx];
                idx++;
            } else {
                maxReach += maxReach + 1;
                ans++;
            }
        }

        while (maxReach < target) {
            maxReach += maxReach + 1;
            ans++;
        }

        return ans;
    }
}
