// Copyright (C) 2022 by iamslash

import java.util.*;

// cards: 3 4 2 3 4 7

// 66ms 90.32% 52.5MB 98.80%
// hash map
// O(N) O(N)
class Solution {
    public int minimumCardPickup(int[] cards) {
        int MAXVAL = 1000000;
        int[] lastIdxs = new int[1000001];
        Arrays.fill(lastIdxs, -1);
        int minCnt = MAXVAL;
        for (int i = 0; i < cards.length; ++i) {
            int card = cards[i];
            if (lastIdxs[card] >= 0) {
                minCnt = Math.min(minCnt, i - lastIdxs[card] + 1);
            }
            lastIdxs[card] = i;
        }
        if (minCnt == MAXVAL) {
            return -1;
        }
        return minCnt;
    }
}
