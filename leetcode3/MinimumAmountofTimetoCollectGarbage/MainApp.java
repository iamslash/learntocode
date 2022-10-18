// Copyright (C) 2022 by iamslash

import java.util.*;

// garbage: G P GP GG
//  travel:   2  4  3
//               i
//   lasts: P M G
//          2 0 3
//    cost: 8

// 32ms 85.14% 68.1MB 94.18%
// hash map
// O(N) O(1)
class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int cost = 0;
        int[] lasts = new int[3];
        for (int i = 0; i < garbage.length; ++i) {
            cost += garbage[i].length();
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
                if (lasts[j] - 1 >= i) {
                    cost += travel[i];
                }
            }
        }
        return cost;
    }
}
