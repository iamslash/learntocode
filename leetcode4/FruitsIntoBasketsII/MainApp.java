// Copyright (C) 2025 by iamslash

import java.util.*;

//  fruits: 4 2 5
// baskets: 3 5 4

//  fruits: 3 6 1
// baskets: 6 4 7

// 1ms 100.00% 44.96MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int ans = 0, n = fruits.length;

        for (int i = 0; i < n; ++i) {

            int j = 0;
            while (j < n && fruits[i] > baskets[j]) {
                j++;
            }

            if (j < n) {
                baskets[j] = 0;
            } else {
                ans++;
            }
        }

        return ans;
    }
}
