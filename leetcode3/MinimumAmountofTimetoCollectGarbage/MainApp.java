// Copyright (C) 2022 by iamslash

import java.util.*;

// brute force
// O(N) O(1)
class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int cost = 0;
        int[] lasts = new int[3];
        for (int i = 0; i < garbage.length; ++i) {
            cost += garbage[i].length();
            Arrays.fill(uniqCnts, 0);
            for (int j = 0; j < garbage[i].length(); ++j) {
                char c = garbage[i].charAt(j);
                if (c == 'P') {
                    lasts[0] = i;
                } else if (c == 'M') {
                    lasts[1] = i;
                } else {
                    lasts[2] = i;
                }
            }
        }
        for (int i = 0; i < travel.length; ++i) {
            for (int j = 0; j < lasts.length; ++j) {
                if (lasts[j] - 1 <= i) {
                    cost += travel[i];
                }
            }
        }
        return cost;
    }
}
