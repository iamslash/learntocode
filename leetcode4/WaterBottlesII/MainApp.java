// Copyright (C) 2024 by iamslash

import java.util.*;

// full bottles | empty bottles | num exchange | bottles drunk
//           13               0              6               0
//            0              13              6              13
//            1               7              7              13
//            2               0              8              13
//            0               2              8              15

// full bottles | empty bottles | num exchange | bottles drunk
//           10               0              3               0
//            0              10              3              10
//            1               7              4              10
//            2               3              5              10
//            0               5              5              12
//            1               0              6              12
//            0               1              6              13

// 0ms 100.00% 40.3MB 98.06%
// greedy
// O(N) O(1)
class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles = numBottles, emptyBottles = 0;
        int drunkenBottles = 0;

        while (fullBottles > 0 || emptyBottles >= numExchange) {
            // Drink full bottles
            if (fullBottles > 0) {
                drunkenBottles += fullBottles;
                emptyBottles += fullBottles;
                fullBottles = 0;
            }
            // Exchange empty bottles
            if (emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                fullBottles += 1;
                numExchange++;
            }
        }

        return drunkenBottles;
    }
}
