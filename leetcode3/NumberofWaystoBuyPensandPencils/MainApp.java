// Copyright (C) 2022 by iamslash

import java.util.*;

// 10 5
//  5
//  2
//  6 3

// 11ms 100.00% 39MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long cnt = 0;
        if (cost1 < cost2) {
            int tmp = cost1;
            cost1 = cost2;
            cost2 = tmp;
        }
        // System.out.printf("total: %d, cost1: %d, cost2: %d\n", total, cost1, cost2);
        while (total >= 0) {
            int quo = total / cost2;
            cnt += quo + 1;
            total -= cost1;
        }
        return cnt;
    }
}
