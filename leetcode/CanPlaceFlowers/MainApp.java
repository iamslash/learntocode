// Copyright (C) 2023 by iamslash


// flowers: 1 0 0 0 1

// greedy
// O(N) O(1)
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int m = flowerbed.length;
        for (int i = 0; i < m && n > 0; ++i) {
            if (flowerbed[i] == 1) {
                continue;
            }
            int prev = (i == 0) ? 0 : flowerbed[i - 1];
            int next = (i == m - 1) ? 0 : flowerbed[i + 1];
            if (prev == 0 && next == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }
}
