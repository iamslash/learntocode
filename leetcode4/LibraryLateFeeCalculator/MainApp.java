// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 98.65% 44.68MB 19.59% 
// brute force
// O(N) O(1)
class Solution {
    public int lateFee(int[] daysLate) {
        int penaltySum = 0;

        for (int dayLate : daysLate) {
            int penalty = dayLate;

            if (2 <= dayLate && dayLate <= 5) {
                penalty = 2 * dayLate;
            } else if (dayLate > 5) {
                penalty = 3 * dayLate;
            }

            penaltySum += penalty;
        }

        return penaltySum;
    }
}
