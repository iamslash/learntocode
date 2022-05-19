// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: greedy
//
// startAt should be represented to 4 digits.  2 for min, 2 for sec.
// 3 digits of sec can not be represented. Consider startAt to 2
// digits 2 digits of sec. There are just 2 cases.
// 0) min, sec
// 1) min-1, sec+60 (sec+60 <= 99)
// 
// ex)
//      startAt: 1
//     moveCost: 2
//     pushCost: 1
//   targetSecs: 600
//   10 min 00 sec    1 + 2 + 1 + 1 + 1 = 6
//    9 min 60 sec    2 + 1 + 2 + 1 + 2 + 1 = 9
// ex)
//      startAt: 0
//     moveCost: 1
//     pushCost: 2
//   targetSecs: 76
//    1 min 16 sec    1 + 2 + 2 + 1 + 2 = 8
//    0 min 76 sec    1 + 2 + 1 + 2 = 6

// 11ms 13.33% 39.8MB 77.95%
// greedy
// O(N) O(1)
class Solution {
    private int getCost(int startAt, int moveCost, int pushCost, int min, int sec) {
        // System.out.printf("min: %d, sec: %d\n", min, sec);
        if (min < 0 || min >= 100 || sec >= 100) {
            return Integer.MAX_VALUE;
        }
        int cost = 0, prevAt = startAt;
        StringBuilder sb = new StringBuilder();
        if (min > 0) {
            sb.append(Integer.toString(min));
            sb.append(String.format("%02d", sec));
        } else {
            sb.append(Integer.toString(sec));
        }
        // System.out.println(sb.toString());
        for (char c : sb.toString().toCharArray()) {
            if (prevAt != c-'0') {
                cost += moveCost;
            }
            cost += pushCost;
            prevAt = c-'0';
        }
        return cost; 
    }
    public int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int min = targetSeconds / 60;
        int sec = targetSeconds % 60;
        return Math.min(getCost(startAt, moveCost, pushCost, min, sec),
                        getCost(startAt, moveCost, pushCost, min-1, sec+60));
    }
}
